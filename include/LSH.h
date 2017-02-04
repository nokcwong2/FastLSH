//
// Created by peter on 17-2-4.
//

#include <vector>
#include <cstddef>
#include <string>

#ifndef FASTLSH_LSH_H
#define FASTLSH_LSH_H

typedef std::vector<std::vector<std::vector<double>>> vector3D;
typedef std::vector<std::vector<double>> vector2D;
typedef std::vector<double> vector1D;

class LSH{
    public:

    LSH();

    LSH(size_t N, size_t D, size_t L, size_t K, double W, size_t Q);
    vector2D loadDataFromLinuxSystem(std::string filePath, size_t row, size_t col);
        vector3D generateRandomLine(size_t L, size_t K, size_t D);
        vector1D generateUniformRandomVector(size_t number, double maxium);
        vector2D computeHash(vector2D dataset, size_t L, double W, size_t N, size_t D, size_t K);
    void loadSetN(std::string filePath);

    void loadSetQ(std::string filePath);




    private:

        size_t N; //# of vectors in the dataset
        size_t Q; //# of vertors in the queryset
        size_t D; //# of dimensions
        size_t L; //# of group hash
        size_t K; //# the number of hash functions in each group hash
        size_t M; //# of dimensions at projection space
        double W; //bucket width
        size_t mSize;
        vector3D randomLine;
        vector1D randomVector;
        vector2D setN;
        vector2D setQ;


    vector2D computeCollision(vector2D hMatrixN, vector2D hMatrixQ, size_t L, size_t nN, size_t nQ);

};


#endif //FASTLSH_LSH_H
