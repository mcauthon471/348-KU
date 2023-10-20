#include <iostream>
#include <fstream>
#include <string>

const int MAXSIZE = 50;

void readMatrixFromFile(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int &size, std::string filename);
void printMatrix(int matrix[MAXSIZE][MAXSIZE], int size);
void matrixAdd(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int matrixSum[MAXSIZE][MAXSIZE], int size);
void matrixProduct(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int matrixProduct[MAXSIZE][MAXSIZE], int size);
void matrixDifference(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int matrixdiff[MAXSIZE][MAXSIZE], int size);

int main(){
    int matrixA[MAXSIZE][MAXSIZE];
    int matrixB[MAXSIZE][MAXSIZE];
    int size;
    int matrixProd[MAXSIZE][MAXSIZE];
    int matrixSum[MAXSIZE][MAXSIZE];
    int matrixDiff[MAXSIZE][MAXSIZE];
    std::string fileName;
    std::cout << "Enter the name of the file: ";
    std::cin >> fileName;
    readMatrixFromFile(matrixA, matrixB, size, fileName);
    std::cout << "Matrix A: " << std::endl;
    printMatrix(matrixA, size);
    std::cout << "Matrix B: " << std::endl;
    printMatrix(matrixB, size);
    matrixAdd(matrixA, matrixB, matrixSum, size);
    matrixProduct(matrixA, matrixB, matrixProd, size);
    matrixDifference(matrixA, matrixB, matrixDiff, size);
    return 0;
}







void readMatrixFromFile(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int &size, std::string fileName) {
    std::ifstream file(fileName);
    if (!file){
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }
    file >> size;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            file >> matrixA[i][j];
        }
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            file >> matrixB[i][j];
        }
    }
}
void printMatrix(int matrix[MAXSIZE][MAXSIZE], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void matrixAdd(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int matrixSum[MAXSIZE][MAXSIZE], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    std::cout << "Matrix Sum: " << std::endl;
    printMatrix(matrixSum, size);
}

void matrixProduct(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int matrixProduct[MAXSIZE][MAXSIZE], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            for (int k = 0; k < size; k++){
                sum += matrixA[i][k] * matrixB[k][j];
            }
            matrixProduct[i][j] = sum;
            sum = 0;
        }
    }
    std::cout << "Matrix Product: " << std::endl;
    printMatrix(matrixProduct, size);
}

void matrixDifference(int matrixA[MAXSIZE][MAXSIZE], int matrixB[MAXSIZE][MAXSIZE], int matrixDiff[MAXSIZE][MAXSIZE], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrixDiff[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    std::cout << "Matrix Difference: " << std::endl;
    printMatrix(matrixDiff, size);
}