//
// Created by peter on 17-2-7.
//
#include <pthread.h>
#include <random>
#include <iostream>
#include <algorithm>
#include "../../include/LSH.h"

#ifdef _WIN32
#include <windows.h>
#elif MACOS
#include <sys/param.h>
#include <sys/sysctl.h>
#else
#include <unistd.h>
#endif

int getNumOfCores() {
#ifdef WIN32
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;
#elif MACOS
    int nm[2];
    size_t len = 4;
    uint32_t count;

    nm[0] = CTL_HW; nm[1] = HW_AVAILCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);

    if(count < 1) {
        nm[1] = HW_NCPU;
        sysctl(nm, 2, &count, &len, NULL, 0);
        if(count < 1) { count = 1; }
    }
    return count;
#else
    return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}


struct nLoopHashParaF{
    int bi;
    int ei;
    int inloop;
    vector2D* hashMatrix;
    vector2D* dataset;
};

struct nLoopColliPara{
    int bi;
    int ei;
    int inloop;
    vector2D* collisionMatrix;
    vector2D* hMatrixQ;
    vector2D* hMatrixN;
};


void* LSH::computeHashPthreadFuc(void *loopPara)
{
    struct nLoopHashParaF *my_data;
    int bi,ei,inloop;
    my_data = (nLoopHashParaF *) loopPara;

    bi = my_data->bi;
    ei = my_data->ei;
    inloop = my_data->inloop;

    for(int i = bi;i<ei;i++)
    {
        // inner loop
        {
            int n = i/inloop; //retrive outer loop index
            int l = i%inloop; //retrive inner loop index
            // (optional) make output critical
            double hashFinalValue = 0;
            //loop through the inner of a hash function group
            for (int k = 0; k < K; ++k) {
                double dTemp = 0;
                //loop through all the dimensions
                for (int d = 0; d < D; ++d) {
                    //vector(math) multiply to make projection
                    dTemp += (*(my_data->dataset))[n][d]*randomLine[l][k][d];
                }
                //assign hashvalue into bucket
                double hashvalue = floor(dTemp/W);
                //merge hash group results **see documentation
                hashFinalValue = hashvalue*randomVector[k] + hashFinalValue;
            }
            (*(my_data->hashMatrix))[n][l] = hashFinalValue;

        }
    }
    return NULL;
}



void* LSH::computeCollisionPthreadFuc(void *loopPara)
{
    struct nLoopColliPara *my_data;
    int bi,ei,inloop;
    my_data = (nLoopColliPara *) loopPara;

    bi = my_data->bi;
    ei = my_data->ei;
    inloop = my_data->inloop;

    for(int i = bi;i<ei;i++)
    {
        // inner loop
        {
            int q = i/inloop;
            int n = i%inloop;
            for (int hash_id = 0; hash_id < L; ++hash_id) {
                if ((*(my_data->hMatrixQ))[n][hash_id] == (*(my_data->hMatrixQ))[q][hash_id])
                    (*my_data->collisionMatrix)[q][n]++;
            }
        }
    }
    return NULL;
}



vector2D LSH::computeHash_pthread(vector2D dataset, size_t pointNum){
    vector2D hashMatrix;

    for (int i = 0; i < pointNum; ++i) {
        vector1D vL(L,0);
        hashMatrix.push_back(vL);
    }

    // it is a implementation of nested loop to stdthread
    const size_t nthreads = getNumOfCores();
    const size_t outloop = pointNum;
    const size_t inloop = L;
    const size_t nloop = outloop*inloop;


    std::vector<pthread_t> threads(nthreads);
    std::vector<nLoopHashParaF> thread_args(nthreads);

    /* spawn the threads */
    for (int t=0; t<nthreads; ++t)
    {
        nLoopHashParaF tempPara;
        tempPara.bi = t*nloop/nthreads;
        tempPara.ei = (t+1)==nthreads?nloop:(t+1)*nloop/nthreads;
        tempPara.inloop = inloop;
        tempPara.dataset = &dataset;
        tempPara.hashMatrix = &hashMatrix;
        thread_args[t] = tempPara;

        pthread_create(&threads[t], NULL, computeHashPthreadFuc, (void*)static_cast<nLoopHashParaF*>(&(thread_args[t])));
    }

    /* wait for threads to finish */
    for (int t=0; t<nthreads; ++t) {
        pthread_join(threads[t], NULL);
    }

    return hashMatrix;
}







vector2D LSH::computeCollision_pthread(vector2D hMatrixN, vector2D hMatrixQ){
    vector2D collisionMatrix;
    for (int i = 0; i < Q ; ++i) {
        vector1D singleLine(N, 0);
        collisionMatrix.push_back(singleLine);
    }

    const size_t nthreads = getNumOfCores();
    const size_t outloop = Q;
    const size_t inloop = N;
    const size_t nloop = outloop*inloop;

    std::vector<pthread_t> threads(nthreads);
    std::vector<nLoopColliPara> thread_args(nthreads);

    /* spawn the threads */
    for (int t=0; t<nthreads; ++t)
    {
        nLoopColliPara tempPara;
        tempPara.bi = t*nloop/nthreads;
        tempPara.ei = (t+1)==nthreads?nloop:(t+1)*nloop/nthreads;
        tempPara.inloop = inloop;
        tempPara.hMatrixN = &hashMatrixN;
        tempPara.hMatrixQ = &hashMatrixQ;
        tempPara.collisionMatrix = &collisionMatrix;
        thread_args[t] = tempPara;

        pthread_create(&threads[t], NULL, computeCollisionPthreadFuc, (void*)&(thread_args[t]));
    }

    /* wait for threads to finish */
    for (int t=0; t<nthreads; ++t) {
        pthread_join(threads[t], NULL);
    }

    return collisionMatrix;
}




