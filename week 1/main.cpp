#include "./handin1/2_6.h"
#include "./handin1/2_6.cpp"
#include "./handin1/3_3.h"
#include "./handin1/3_3.cpp"
#include "./handin1/5_3.h"
#include "./handin1/5_3.cpp"
#include "./handin1/5_4.h"
#include "./handin1/5_4.cpp"
#include "./handin1/5_6.h"
#include "./handin1/5_6.cpp"
#include "./handin1/5_9.h"
#include "./handin1/5_9.cpp"
#include "./handin1/5_10.h"
#include "./handin1/5_10.cpp"
#include <iostream>

int main(int argc, char* argv[]){

    #pragma region 2.6
    std::cout << "Excersise 2.6:\n";
    double initialGuess_26 = 0.0;
    double epsilon_26 = 0.0001;
    newton_Raphson(initialGuess_26,epsilon_26);
    #pragma endregion
 
    #pragma region 3.3
    std::cout << "\nExcersise 3.3:\n";
    int n_33 = atoi(argv[1]);
    implicit_Euler(n_33);
    #pragma endregion

    #pragma region 5.3
    std::cout << "\nExcersise 5.3:\n";
    double *a_53, *b_53;
    a_53 = new double;
    b_53 = new double;
    *a_53 = 2.2;
    *b_53 = 3.3;
    swap_pointer(a_53,b_53);
    delete a_53;
    delete b_53;

    double c_53 = 2.2, d_53 = 3.3;
    swap_ref(c_53,d_53);
    #pragma endregion

    #pragma region 5.4
    std::cout << "\nExcersise 5.4:\n";
    double a_54[5] = {1.0,2.0,3.0,4.0,5.0};
    int length_54 = 5;
    calc_std(a_54,length_54);
    #pragma endregion

    #pragma region 5.6
    std::cout << "\nExcersise 5.6:\n";
    /* Test Matrix x matrix
    double **A, **B, **res;
    int ARows = 3, ACols = 3, BRows = 3,BCols = 3;

    // Allocate memory for A
    A = new double*[ARows];
    for (int i = 0; i < ARows; ++i) 
    {
        A[i] = new double[ACols];
    }

    // Initialize A with values
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    // Allocate memory for B
    B = new double*[BRows];
    for (int i = 0; i < BRows; ++i) 
    {
        B[i] = new double[BCols];
    }

    // Initialize B with values
    B[0][0] = 9; B[0][1] = 8; B[0][2] = 7;
    B[1][0] = 6; B[1][1] = 5; B[1][2] = 4;
    B[2][0] = 3; B[2][1] = 2; B[2][2] = 1;

    // Allocate memory for res
    res = new double*[ARows];
    for (int i = 0; i < ARows; ++i) 
    {
        res[i] = new double[BCols];
    }

    // Initialize res with zero values
    res[0][0] = 0; res[0][1] = 0; res[0][2] = 0;
    res[1][0] = 0; res[1][1] = 0; res[1][2] = 0;
    res[2][0] = 0; res[2][1] = 0; res[2][2] = 0;
    
    Multiply(res,A,B,ARows,ACols,BRows,BCols);

    for (int i = 0; i < ARows; ++i) 
    {
    for (int j = 0; j < BCols; ++j) 
        {
        std::cout << res[i][j] << " ";
        }
    std::cout << std::endl;
    }
    // Deallocate memory
    for (int i = 0; i < ARows; ++i) 
    {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < BRows; ++i) 
    {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < ARows; ++i) 
    {
        delete[] res[i];
    }
    delete[] res;


    */
    /* Test Vector x matrix
    double **B;
    double* A = new double[3]{1, 2, 3};
    double* res = new double[3]{0,0,0};
    int ACols = 3, BRows = 3,BCols = 3;

    // Allocate memory for B
    B = new double*[BRows];
    for (int i = 0; i < BRows; ++i) 
    {
        B[i] = new double[BCols];
    }

    // Initialize B with values
    B[0][0] = 9; B[0][1] = 8; B[0][2] = 7;
    B[1][0] = 6; B[1][1] = 5; B[1][2] = 4;
    B[2][0] = 3; B[2][1] = 2; B[2][2] = 1;

    Multiply(res, A, B, ACols, BRows, BCols);
    for (int i = 0; i < ACols; i++){
        std::cout << res[i] << " , ";
    }
    // Deallocate memory
    for (int i = 0; i < BRows; ++i) 
    {
        delete[] B[i];
    }
    delete[] B;
    delete[] A;
    delete[] res;
    */
    /* Test Matrix x vector
    double **A;
    int ACols = 3, ARows = 3,BRows = 3;
    double* B = new double[3]{1, 2, 3};
    double* res = new double[3]{0,0,0};

    // Allocate memory for A
    A = new double*[ARows];
    for (int i = 0; i < ARows; ++i) 
    {
        A[i] = new double[ACols];
    }

    // Initialize A with values
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    Multiply(res,A,B, ARows,ACols,BRows);
    for (int i = 0; i < ARows; i++){
        std::cout << res[i] << " , ";
    }

    // Deallocate memory
    for (int i = 0; i < ARows; ++i) 
    {
        delete[] A[i];
    }
    delete[] A;
    delete[] B;
    delete[] res;
    */
    /* Test Scalar times matrix
    double scalar = 4.4;
    double **B, **res;
    int BRows = 3,BCols = 3;
    // Allocate memory for B
    B = new double*[BRows];
    for (int i = 0; i < BRows; ++i) 
    {
        B[i] = new double[BCols];
    }

    // Initialize B with values
    B[0][0] = 9; B[0][1] = 8; B[0][2] = 7;
    B[1][0] = 6; B[1][1] = 5; B[1][2] = 4;
    B[2][0] = 3; B[2][1] = 2; B[2][2] = 1;

    // Allocate memory for res
    res = new double*[BRows];
    for (int i = 0; i < BRows; ++i) 
    {
        res[i] = new double[BCols];
    }

    // Initialize res with zero values
    res[0][0] = 0; res[0][1] = 0; res[0][2] = 0;
    res[1][0] = 0; res[1][1] = 0; res[1][2] = 0;
    res[2][0] = 0; res[2][1] = 0; res[2][2] = 0;

    Multiply(res,scalar,B,BRows,BCols);

    for (int i = 0; i < BRows; ++i) 
    {
    for (int j = 0; j < BCols; ++j) 
        {
        std::cout << res[i][j] << " ";
        }
    std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < BRows; ++i) 
    {
        delete[] B[i];
    }
    for (int i = 0; i < BRows; ++i) 
    {
        delete[] res[i];
    }
    delete[] B;
    delete[] res;
    */
    /*Test Matrix times scalar
        double scalar = 4.4;
    double **B, **res;
    // Allocate memory for B
        B = new double*[BRows];
        for (int i = 0; i < BRows; ++i) 
        {
            B[i] = new double[BCols];
        }

        // Initialize B with values
        B[0][0] = 9; B[0][1] = 8; B[0][2] = 7;
        B[1][0] = 6; B[1][1] = 5; B[1][2] = 4;
        B[2][0] = 3; B[2][1] = 2; B[2][2] = 1;

        // Allocate memory for res
        res = new double*[BRows];
        for (int i = 0; i < BRows; ++i) 
        {
            res[i] = new double[BCols];
        }

        // Initialize res with zero values
        res[0][0] = 0; res[0][1] = 0; res[0][2] = 0;
        res[1][0] = 0; res[1][1] = 0; res[1][2] = 0;
        res[2][0] = 0; res[2][1] = 0; res[2][2] = 0;

        Multiply(res,B,scalar,BRows,BCols);

        //Deallocate memory
        for (int i = 0; i < BRows; ++i) 
        {
        for (int j = 0; j < BCols; ++j) 
            {
            std::cout << res[i][j] << " ";
            }
        std::cout << std::endl;
        }

            // Deallocate memory
        for (int i = 0; i < BRows; ++i) 
        {
            delete[] B[i];
        }
        for (int i = 0; i < BRows; ++i) 
        {
            delete[] res[i];
        }
        delete[] B;
        delete[] res;
        */
    #pragma endregion

    #pragma region 5.9
    std::cout << "\nExcersise 5.9:\n";
    double **A_59;
    int ARows_59 = 3, ACols_59 = 3;

    // Allocate memory for A
    A_59 = new double*[ARows_59];
    for (int i = 0; i < ARows_59; ++i) 
    {
        A_59[i] = new double[ACols_59];
    }
    
    // Initialize A with values
    A_59[0][0] = 1; A_59[0][1] = 2; A_59[0][2] = 3;
    A_59[1][0] = 0; A_59[1][1] = 1; A_59[1][2] = 4;
    A_59[2][0] = 5; A_59[2][1] = 6; A_59[2][2] = 0;
    
    /* Singular matrix
    A_59[0][0] = 1; A_59[0][1] = 2; A_59[0][2] = 3;
    A_59[1][0] = 4; A_59[1][1] = 5; A_59[1][2] = 6;
    A_59[2][0] = 7; A_59[2][1] = 8; A_59[2][2] = 9;
    */

    double* b_59 = new double[3]{5,10,15};
    double* u_59 = new double[3]{0};

    solve3by3(A_59,b_59,u_59);

    std::cout << "Solution vector:\n";
    for(int i = 0; i < ARows_59; i++) {
        std::cout << "u[" << i << "] = " << u_59[i] << std::endl;
    }
    #pragma endregion

    #pragma region 5.10
    std::cout << "\nExcersise 5.10:\n";

    //We test with matrix from 5.9
    guassian_elimination(A_59,b_59,u_59,ARows_59);

    // Deallocate memory
    for (int i = 0; i < ARows_59; ++i) 
    {
        delete[] A_59[i];
    }
    delete[] A_59;
    delete[] b_59;
    delete[] u_59;
    #pragma endregion

  return 0;
}