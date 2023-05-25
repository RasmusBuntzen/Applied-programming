#include "CalculateExponential.hpp"
#include <cmath>


void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res);
void MatrixMultiply(ComplexNumber **A,ComplexNumber **B);
double factorial(int n);
void MatrixDivideScalar(ComplexNumber **A,double scalar);
void AddMatricies(ComplexNumber **A,ComplexNumber **B);

void MatrixMultiply(ComplexNumber **A,ComplexNumber **B, ComplexNumber** result){
    //We need to be able to multiply two matrices of complex numbers
for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
        result[i][j] = ComplexNumber(0, 0);
    }
}

    for(int i = 0; i < 3; i++){ //goes through the rows in A and result
        for(int j = 0; j < 3; j++){ //Goes through cols in B and result
            for(int k = 0; k < 3; k++){ //goes through the cols in A and rows in B
                result[i][j] = result[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

double factorial(int n) { //I use this var type to be able to store large integers such as 50!
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void MatrixDivideScalar(ComplexNumber **A, double scalar,ComplexNumber** result) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = ComplexNumber(RealPart(A[i][j]) / scalar, ImaginaryPart(A[i][j]) / scalar);
        }
    }
}

void AddMatricies(ComplexNumber **A,ComplexNumber **B,ComplexNumber** result){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){
    //We need an matrix to store A^n-1 in order to calculate A^n, and a matrix to store A^n/n!
    ComplexNumber **A_to_n;
    ComplexNumber **temp_sum;
    ComplexNumber **result;
    A_to_n = new ComplexNumber*[3];
    temp_sum = new ComplexNumber*[3];
    result = new ComplexNumber*[3];
    for (int i = 0; i < 3; ++i) 
        {
            A_to_n[i] = new ComplexNumber[3];
            temp_sum[i] = new ComplexNumber[3];
            result[i] = new ComplexNumber[3];
        }
    A_to_n[0][0] = 1; 
    A_to_n[1][1] = 1; 
    A_to_n[2][2] = 1;

    res[0][0] = 1; 
    res[1][1] = 1; 
    res[2][2] = 1;

  
            std::cout << "Initial res: \n";  
            for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                std::cout << res[j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    
    for(int i = 1; i < nMax; i++){ //Obs i start from i = 1 and not 0. This is because i initiate res as the identity matrix (this allows me to not do A^0 calculation)
        std::cout << "Iteration " << i << ":" << std::endl;
        std::cout << "Factorial =  " << factorial(i) << std::endl;

        MatrixMultiply(A_to_n,A,result); //Output is stored in result. For n: calculates and stores A^n-1 * A
        for(int j = 0; j < 3; j++){ // coppy result into A_to_n
            for(int k = 0; k < 3; k++){
            A_to_n[j][k] = result[j][k];
            }
        }

        MatrixDivideScalar(A_to_n,factorial(i),result); //Output is stored in result. For n: takes A^n and divides w. n!
         for(int j = 0; j < 3; j++){ // coppy result into temp_sum
            for(int k = 0; k < 3; k++){
            temp_sum[j][k] = result[j][k];
            }
        }

        AddMatricies(res,temp_sum,result); //Output is stored in result. We add the curent sum to the running total sum
         for(int j = 0; j < 3; j++){ // coppy result into res
            for(int k = 0; k < 3; k++){
            res[j][k] = result[j][k];
            }
        }

            std::cout << "res: \n";  //rest of code just prints res in each iteration.
            for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                std::cout << res[j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // deallocate A_to_n, temp_sum and result matrix
    for (int i = 0; i < 3; ++i) {
        delete[] A_to_n[i];
        delete[] temp_sum[i];
        delete[] result[i];
    }
    delete[] A_to_n;
    delete[] temp_sum;
    delete[] result;
}