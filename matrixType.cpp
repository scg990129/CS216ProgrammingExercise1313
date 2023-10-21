//
// Created by Jacob Yeung on 10/18/23.
//

#include <sstream>
#include "matrixType.h"
#include <iostream>
#include <vector>

matrixType::~matrixType() {
    for(int** ptrRow = matrix; ptrRow < matrix + this->getRowM(); ptrRow++){
        delete[] *ptrRow;
    }
    delete[] this->matrix;
}
matrixType::matrixType(int rowM, int colN, std::istream &is): matrixType(rowM, colN){ // empty matrix
    string rowString;
    int element;
        for (int row = 0; row < this->getRowM(); row++){
        getline(is >> std::ws, rowString) ;
        stringstream ss(rowString);
        for(int col = 0; col < this->getColN(); col++){
            ss >> element;
            this->matrix[row][col] = element;
        }
    }
}
matrixType::matrixType(int rowM, int colN){ // empty matrix
    this->rowM = rowM;
    this->colN = colN;
    matrix = new int *[this->getRowM()];
    for (int i = 0; i < rowM; i++) {
        matrix[i] = new int[this->colN];
    }
}

int matrixType::getRowM() const{
    return this->rowM;
}
int matrixType::getColN() const{
    return this->colN;
}

std::ostream &operator<<(std::ostream &os, const matrixType &type) {
    for(int** ptrRow = type.matrix; ptrRow < type.matrix + type.getRowM(); ptrRow++){
        for(int* ptrCol = *ptrRow; ptrCol < *ptrRow + type.getColN(); ptrCol++){
            os << *ptrCol << " ";
        }
        os << std::endl;
    }
    return os;
}

