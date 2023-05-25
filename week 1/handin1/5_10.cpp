#include "5_10.h"
#include <iostream>

void guassian_elimination(double **A, double *b, double *u, int n);
double** augmentation(double **A, double *b,int n);
int pivot(double** A_b,int iteration,int n);
double** swap_rows(double** A_b,int maxRow, int iteration,int n);
double** eleminate(double** A_b,int iteration, int n);
void back_substitution(double** A_b, double* u, int n);

double** augmentation(double **A, double *b,int n){
   //start by augmenting A and b into a single matrix
    double** A_b = new double*[n]; //the matrix shoulb be n by n+1 which we allocate dynamicaly
    for(int i = 0; i < n; i++){ //rows
    //We just loop through the entire A_b matrix and fill it as we go. We start in row 0 and fille the columns left to right, then move to next row until the entire matrix is full
        A_b[i] = new double[n+1];
        for(int j = 0; j < n+1; j++){ //columns
            if(j == n){ //When this is true we fill with values from b
                A_b[i][j] = b[i];
            }
            else{ //otherwise we fill with values from A
                A_b[i][j] = A[i][j];
            }
        }
    } 
    return A_b;
}

int pivot(double** A_b,int iteration,int n){
    //We find the largest value in the current row. The row with the lastest value is used as pivot
    double maxVal = A_b[iteration][iteration];
    int maxRow = iteration;

    for(int i = iteration; i < n; i++){ //loop rows in A_b and later subsystems
        //find row with largest value in column 0 in 1st iteration, column 2 in 2nd iteration and so on
        if(A_b[i][iteration] > maxVal){
            maxVal = A_b[i][iteration];
            maxRow = i;
        }
    }
    return maxRow;
}

double** swap_rows(double** A_b,int maxRow, int iteration,int n){
    for (int j = iteration; j < n+1; j++) { //loop rows
    double temp = A_b[iteration][j];
    A_b[iteration][j] = A_b[maxRow][j];
    A_b[maxRow][j] = temp;
    }   
    return A_b;
}

double** eleminate(double** A_b,int iteration, int n){
    for(int i = iteration+1; i < n; i++){//loops all rows that should be eleminated
        double factor =  A_b[i][iteration] / A_b[iteration][iteration]; //factor is calculated form row 0 col 0 in iteration 1, row 1 col 1 in iteration 2 and so on (I.E pivot elements)

        for(int j = iteration; j < n+1; j++){ //loops all columns that should be eleminated. 
            A_b[i][j] = A_b[i][j] - factor * A_b[iteration][j]; //elemination element - eleminator element * factor
        }
    }
    return A_b;
}

void back_substitution(double** A_b, double* u, int n){
    for(int i = n - 1; i >= 0; i--) {   // Iterate over the rows of the upper triangular matrix in reverse order
    double sum = 0;
        for(int j = i + 1; j < n; j++) {   // Iterate over the remaining columns in the current row. n-1 for last row, n-1 and n-2 for 2nd to last row and so on
            sum += A_b[i][j] * u[j];   // Accumulate the sum of (element * solution) (fx if we are at top row and have 5x1 + 6x2 + 0x3 = 15, we know x2 and x3 so we simply substitute them in)
        }
    u[i] = (A_b[i][n] - sum) / A_b[i][i];   // Solve for the solution of the current row (what we calculated in sum we "move" to the right side and divide by the factor infront of x to isolate x)
    }
}

void guassian_elimination(double **A, double *b, double *u, int n){
    //We augment A and b into a single matrix. By doing this we can perform all matrix operations on the same matrix insted of 2 seperate ones.
    double** A_b = augmentation(A,b,n);
    std::cout << "Augmented start matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
        std::cout << A_b[i][j] << " ";
        }
    std::cout << std::endl;
    }
    
    int iteration = 0;
    for(int i = 0; i < n; i++){ //loop rows of A_B
        int maxRow = pivot(A_b,iteration,n); //find row we should use as pivot

        //Swap top row with the row with the largest value. OBS this is called partial pivoting
        A_b = swap_rows(A_b,maxRow, iteration, n);
    
        //We now have the largest value in the top row of the subsystem. We can now eleminate the below elements.
        A_b = eleminate(A_b,iteration,n);

        iteration += 1;
    }
    //Print array after elemination (should be upper triangular)
    std::cout << "Upper triangluar matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
        std::cout << A_b[i][j] << " ";
        }
    std::cout << std::endl;
    }
    //We now have an upper triangular matrix, we can use back_substituation to solve the equations
    // see https://www.math.usm.edu/lambers/mat610/sum10/lecture4.pdf 
    back_substitution(A_b,u,n);

    std::cout << "Solution vector:\n";
    for(int i = 0; i < n; i++) {
        std::cout << "u[" << i << "] = " << u[i] << std::endl;
    }

    //lastly we deallocate A_b
    for (int i = 0; i < n; i++) {
        delete[] A_b[i];
    }
    delete[] A_b;
}