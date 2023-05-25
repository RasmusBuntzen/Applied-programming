#include "5_4.h"
#include <iostream>
#include <cmath>
#include <cassert>

double calc_std(double a[], int length);
double calc_mean(double a[], int length);

double calc_mean(double a[], int length){
    double temp_sum = 0;
    for (int i = 0; i < length; i++){ //add all elements
        temp_sum = temp_sum + a[i];
    }
    std::cout << "Mean: " << temp_sum/length << "\n";
    return temp_sum/length; //calculate mean
}

double calc_std(double a[], int length){
    if(length == 1){ //if length == 1 the result is undefined. In this case we return 0 as stated in the excersise. 
        std::cout << "SD is undefined as length == 1\n";
        return 0;
    }
    double temp_sum = 0;
    double mean = calc_mean(a, length);
    for (int i = 0; i < length; i++){ //add all elements
        temp_sum = temp_sum + pow((a[i] - mean),2);
    }
    std::cout << "Standard deviation: " << sqrt(temp_sum/(length-1)) << "\n";
    return sqrt(temp_sum/(length-1));
}