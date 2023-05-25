#include<iostream>
#include<algorithm>
#include <string>

#include"armadillo.hpp"
#include"file_managment.hpp"
#include"file_managment.cpp"
#include"LogisticRegression.hpp"

using namespace std;
using namespace arma;


int main(int argc, char* argv[]){
    Logistic_Regression("dataX.dat", "dataXtest.dat", "dataY.dat");

    return 0;
}

mat Gradient_Descent(mat X_train, mat Y_train){
    double alpha = 0.1; //learning rate
    double epsilon = 1e-7;
    vec w_prev(X_train.n_cols, fill::zeros); // initiate the starting guess to be 0 
    vec w_next(X_train.n_cols, fill::zeros); // we need a prev and a next in order to calculate the difference between them to see if we need to break
 
    
    
    double n_samples = X_train.n_rows;// Obs this cant be an int (event though the content always is a whole number), because otherwise when it is used the outbut will also be in

    int iteration = 0;
    while (iteration < 1000000){ // until we break it manually (I.E when  algorithm has converged) or 1.000.000 iterations (normally it takes   126.184 iterations to converge)
        mat inner_sum(X_train.n_cols,1,fill::zeros);
        for( int i = 0; i < n_samples; i++){ //loops through all rows in training data

            mat x = X_train.row(i).t(); // current point from X_train as column vector
            double y = double(Y_train(i)); //current label as a double

            inner_sum +=  y * (1/(1 + exp(y * dot(w_prev.t(), x)))) * x; //calculate the sum in the derevative (see assignment)
            //OBS we need to transpose the left hand side of vector multiplications as armadillo cant do vector multiplication (only matrix multiplication)

        }

        mat df_L = -1/n_samples * inner_sum; //calculate the final derevative

        w_next = w_prev - alpha * df_L; // we update x_next OBS here x_next == x_prev, so they are interchangable
        //cout << "Iteration: " << iteration << "\nConvergence criteria: " << norm(w_next-w_prev,2) << endl;

        
        if(norm(w_next-w_prev,2) < epsilon){ //we check if the difference between x_next and w_prev is small enough that we consider the algorithm converged
            break;
        }
        
        w_prev = w_next; //Now that we have checked convergence criateria we can update x_prev
        iteration++; 
    }
    return w_next;
}

double Get_func_value(mat w, mat x){
    //We calculate f(x) by using w and x
    mat f_x_temp = w.t() * x.t();
    double f_x = f_x_temp(0,0); // f_x_temp is a 1x1 matrix we convert to double
    return f_x;
}

void Logistic_Regression(string X_train_path, string X_test_path, string Y_train_path){
    //First we use the inputted paths to load the test and training data
    mat X_train; mat X_test; mat Y_train;
    X_train = read_file(X_train_path); X_test = read_file(X_test_path); Y_train = read_file(Y_train_path);

    mat labels(X_test.n_rows, 1); //initiate a vector to store the labels


    //We now need to train our model
    mat w =  Gradient_Descent(X_train, Y_train);
    //cout << "w is: " << w << endl;

    for(int i = 0; i < X_test.n_rows; i++){ //A loop that runs through all point in our test data
        double f_x = Get_func_value(w,X_test.row(i));
        //cout << "f(x) = " << f_x << endl;
        if (f_x > 0){ //function value is positive, so we give label 1
            labels(i) = int(1);
        }
        else{ // function value is 0 or negative so we give label -1
            labels(i) = int(-1);
        }
    }
    save_file(labels,"LogReg.dat"); //write label vector to LogReg.dat
}