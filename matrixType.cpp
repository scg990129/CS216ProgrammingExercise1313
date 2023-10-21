//
// Created by Jacob Yeung on 10/18/23.
//

#include <sstream>
#include "matrixType.h"

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

matrixType operator+(const matrixType &type1, const matrixType &type2){
    if (type1.getRowM() != type2.getRowM() || type1.getColN() != type2.getColN()){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    matrixType result(type1.getRowM(), type1.getColN());
    for(int row = 0; row < type1.getRowM(); row++){
        for(int col = 0; col < type1.getColN(); col++){
            result.matrix[row][col] = type1.matrix[row][col] + type2.matrix[row][col];
        }
    }
    return result;
}

matrixType operator-(const matrixType &type1, const matrixType &type2){
    if (type1.getRowM() != type2.getRowM() || type1.getColN() != type2.getColN()){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    matrixType result(type1.getRowM(), type1.getColN());
    for(int row = 0; row < type1.getRowM(); row++){
        for(int col = 0; col < type1.getColN(); col++){
            result.matrix[row][col] = type1.matrix[row][col] - type2.matrix[row][col];
        }
    }
    return result;
}

matrixType operator*(const matrixType &type1, const matrixType &type2){
    if (type1.getColN() != type2.getRowM()){
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    matrixType result(type1.getRowM(), type2.getColN()); //
    for(int row = 0; row < type1.getRowM(); row++){
        for(int col = 0; col < type2.getColN(); col++){
            result.matrix[row][col] = 0;
            for(int i = 0; i < type1.getColN(); i++){
                result.matrix[row][col] += type1.matrix[row][i] * type2.matrix[i][col];
//                printf("[%i][%i] =+ type1.matrix[%i][%i] * type2.matrix[%i][%i];\n",
//                       row, col, row, i, i, col
//                       );
            }

//            for(int i = 0; i < type1.getColN(); i++){
//                result.matrix[row][col] += type1.matrix[row][i] * type2.matrix[i][col];
//            }
        }
    }
    return result;
}
