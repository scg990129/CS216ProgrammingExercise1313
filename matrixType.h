//
// Created by Jacob Yeung on 10/18/23.
//

#ifndef CS216PROGRAMMINGEXERCISE1313_MATRIXTYPE_H
#define CS216PROGRAMMINGEXERCISE1313_MATRIXTYPE_H

#include <iostream>

using namespace std;

class matrixType {
protected:
    int rowM, colN; // row = m, col = n
    int **matrix; //= int[5][6]; // 5 X 6: 5 row x 6 col
public:
    matrixType(int rowM, int colN, std::istream &is); // empty matrix
    matrixType(int rowM, int colN); // empty matrix
    ~matrixType();

    int getRowM() const;
    int getColN() const;
//    matrixType getThis() const;

    friend std::ostream &operator<<(std::ostream &os, const matrixType &type);
//    friend std::istream &operator>>(std::istream &is, vector<matrixType> type);

    friend matrixType operator+(const matrixType &type1, const matrixType &type2);
    friend matrixType operator-(const matrixType &type1, const matrixType &type2);
    // [1A, 1B, 1C]
    // [2A, 2B, 2C]
    // [3A, 3B, 3C]
    friend matrixType operator*(const matrixType &type1, const matrixType &type2);
};

#endif //CS216PROGRAMMINGEXERCISE1313_MATRIXTYPE_H
