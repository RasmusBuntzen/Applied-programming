#include "5_6.h"
#include <iostream>



void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols);
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) ;
void Multiply(double **res, double **B, double scalar, int BRows, int BCols) ;

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols){
    //Matrix times matrix
    if (ACols != BRows){
        std::cout << "Input not of correct dimensions";
        res = 0;
    }
    std::cout << "Matrix times matrix: \n";
    // we assume that res is of correct size (Arows*BCols) and all elements is zero
    for(int i = 0; i < ARows; i++){ //loops through rows of A
        for(int j = 0; j < BCols; j++){ //loops through cols of B
            for(int k = 0; k < ACols; k++){//loops through cols of A
                res[i][j] += A[i][k] * B[k][j];  // we here use that cols in A == rows in B, so we use k to increment both.
            }
        }
    }
}

void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){
    //vector times matrix
    if (ACols != BRows){
        std::cout << "Input not of correct dimensions";
        res = 0;
    }
    std::cout << "Vector times matrix: \n";
    for (int i = 0; i < BRows; i++) {
            for (int j = 0; j < ACols; j++) {
                res[i] += A[j] * B[j][i]; //We use that ACols == BRows so we increment both by j
            }
        }
}

void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
    //Matrix times vector
    if (ACols != BRows){
        std::cout << "Input not of correct dimensions";
        res = 0;
    }
    std::cout << "Matrix times Vector: \n";
    // we assume that res is of correct size (Arows*BCols) and all elements is zero
    for(int i = 0; i < ARows; i++){ //loops through rows of A (matrix)
        for(int j = 0; j < BRows; j++){ //loops through rows of B (vector)
                res[i] += A[i][j] * B[j];  // We use that ACols == BRows so we use J to increment both
        }
    }
}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols){
    std::cout << "Scalar times matrix: \n";
    for(int i = 0; i < BRows; i++){
        for(int j = 0; j < BCols; j++){
            res[i][j] = B[i][j] * scalar;
        }
    }
}

void Multiply(double **res, double **B, double scalar, int BRows, int BCols){
    std::cout << "Matrix times scalar: \n";
    for(int i = 0; i < BRows; i++){
        for(int j = 0; j < BCols; j++){
            res[i][j] = B[i][j] * scalar;
        }
    }
}