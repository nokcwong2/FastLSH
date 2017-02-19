//
// Created by peter on 17-2-4.
//

#include <vector>
#include <cstddef>
#include <string>
#include <gtest/gtest_prod.h>

#ifndef FASTLSH_LSH_H
#define FASTLSH_LSH_H

//typedef to make code less verbose
typedef std::vector<std::vector<std::vector<double>>> vector3D;
typedef std::vector<std::vector<double>> vector2D;
typedef std::vector<double> vector1D;

class LSH{
    public:

    LSH();

    LSH(size_t N, size_t D, size_t L, size_t K, double W, size_t Q);

    void loadSetQ(char *filePath, int fileSize);

    void loadSetN(char *filePath, int fileSize);

    bool setUseHdfs(bool useHdfs);

    bool setUseMultiThread(bool useMultiThread);

    bool setMultiThreadMode(int multiMode); //default 0-openMP, 1-stdthread 2-pthread

    bool setDefault();

    vector2D getCollisionMatrix();

    int saveHashNToMemc(const char *server, unsigned short port, time_t exp);

    void readHashNFromMemc(const char *server, unsigned short port, std::string runId);

    int saveHashNToRedis(const char *server, unsigned short port);

    int readHashNFromRedis(const char *server, unsigned short port, std::string srunId);

    void reportStatus();

    int clear();

    int reset();



private:

    size_t N; //# of vectors in the dataset
    size_t Q; //# of vertors in the queryset
    size_t D; //# of dimensions
    size_t L; //# of group hash
    size_t K; //# the number of hash functions in each group hash
    size_t M; //# of dimensions at projection space
    double W; //bucket width
    bool useHdfs; //whether use hdfs flag
    int NfileSize; //N file binary size, for hdfs use
    int QfileSize; //Q file binary size, for hdfs use
    bool useMultiThread;
    int multiThreadMode; //default 0-openMP, 1-stdthread 2-pthread
    std::string runID; //runID for recognize this particular run -- mainly for get value from in-memory storage

    vector3D randomLine; //collection of randomline for points to project on
    vector1D randomVector; //random values to assist k group of LSH
    vector2D setN; // original data set of N
    vector2D setQ; // original data set of Q

    //this two brings extra cost of memory, may merge to the setN, setQ to save memory
    vector2D setNNorm; // normalized data set of N
    vector2D setQNorm; // normalized data set of Q

    vector2D hashMatrixN; // hashMatrix of N where hash value is stored
    vector2D hashMatrixQ; // hashMatrix of Q where hash value is stored


    vector2D computeCollision(vector2D hMatrixN, vector2D hMatrixQ);

    vector3D generateRandomLine();

    vector1D generateUniformRandomVector(size_t number, double maxium);

    vector2D loadDataFromHDFS(char *filePath, int row, int col, int fileSize);

    vector2D loadDataFromLinuxSystem(char *filePath, size_t row, size_t col);

    vector2D computeHash(vector2D dataset, size_t pNum);

    vector2D computeHash_openmp(vector2D dataset, size_t pointNum);

    vector2D computeCollision_openmp(vector2D hMatrixN, vector2D hMatrixQ);

    vector2D computeHash_stdthread(vector2D dataset, size_t pointNum);

    vector2D computeCollision_stdthread(vector2D hMatrixN, vector2D hMatrixQ);

    vector2D computeHash_pthread(vector2D dataset, size_t pointNum);

    vector2D computeCollision_pthread(vector2D hMatrixN, vector2D hMatrixQ);

    friend void *computeHashPthreadFuc(void *loopPara);

    friend void *computeCollisionPthreadFuc(void *loopPara);

    std::string generateRunId();

    vector2D normalize(vector2D dataset);

    FRIEND_TEST(openMPTest, hashValueTest);

    FRIEND_TEST(hdfsTest, readTest);

    FRIEND_TEST(metaTest, linuxReadTest);

    FRIEND_TEST(metaTest, randGeneTest);

    FRIEND_TEST(stdthreadTest, hashValueTest);

    FRIEND_TEST(pthreadTest, hashValueTest);

    FRIEND_TEST(memcachedTest, resultTest);

    FRIEND_TEST(redisTest, resultTest);
};


#endif //FASTLSH_LSH_H
