#include "5_9.h"
#include <iostream>

void solve3by3(double **A, double *b, double *u);
double determinant(double A[3][3]);
double determinant(double **A);

double determinant(double A[3][3]){
    //We calculate the determinant (see: https://www.mathsisfun.com/algebra/matrix-determinant.html)
    double det = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
    return det;
}
double determinant(double **A){
    //We overload the function to work both on pointers and references
    double det = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) - A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
    return det;
}

void solve3by3(double **A, double *b, double *u){
    //We use Cramer's rule (see https://en.wikipedia.org/wiki/Cramer%27s_rule)
    //First we create the matrixes where we substitue a column with b
    double A1[3][3] = { {b[0],A[0][1],A[0][2]},
                        {b[1],A[1][1],A[1][2]},
                        {b[2],A[2][1],A[2][2]}};

    double A2[3][3] = { {A[0][0],b[0],A[0][2]},
                        {A[1][0],b[1],A[1][2]},
                        {A[2][0],b[2],A[2][2]}};

    double A3[3][3] = { {A[0][0],A[0][1],b[0]},
                        {A[1][0],A[1][1],b[1]},
                        {A[2][0],A[2][1],b[2]}};

    double det_A = determinant(A);
    // Check if det_A is zero (system is singular)
    if (det_A == 0) {
        std::cerr << "Error: System is singular (determinant of A is zero)" << std::endl;
        return;
    }
    // we can now calculate u. u1 = det(A_1) / det_A, u2 = det(A2)/det_A...
    u[0] = determinant(A1) / det_A;
    u[1] = determinant(A2) / det_A;
    u[2] = determinant(A3) / det_A;
}