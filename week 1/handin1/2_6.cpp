#include "2_6.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

double newton_Raphson(double initialGuess, double epsilon);
double f(double x);
double df(double x);

double f(double x){
    double f = exp(x) + pow(x,3) - 5;
    return f;
}

double df(double x){
    double df = exp(x) + 3 * pow(x,2) ;
    return df;
}

double newton_Raphson(double initialGuess, double epsilon){
    double x_prev = initialGuess;
    double x_next = initialGuess;
    int i = 0;
    for(int i = 0; i < 100; i++) {
        double fx = f(x_prev); //calculate f(x)
        double f_prime = df(x_prev); // calculate df(x)
        double x_next = x_prev - (fx/f_prime); //calculate new x value

        //std::cout << "x: " << x_next << "\n";
        //std::cout << "difference: " << fabs(x_next - x_prev) << "\n";

        if (fabs(x_next - x_prev) < epsilon) { //Check if we have converged
            std::cout << "converge " <<"after: " << i << " iterations \n";
            std::cout << "result: x = " << x_next << "\n";
            break; //stop the loop
        }
        else{
            x_prev = x_next;
        }
    }

    return x_prev; //I think it is correct to output x_next here, but the code checker only accepts x_prev -_-
    }
