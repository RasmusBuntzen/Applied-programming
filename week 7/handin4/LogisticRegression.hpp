#ifndef LOGISTICREGRESSION
#define LOGISTICREGRESSION
#include<iostream>
#include<algorithm>
#include <string>

#include"armadillo.hpp"
using namespace std;
using namespace arma;

void Logistic_Regression(string X_train_path, string X_test_path, string Y_train_path);

mat Gradient_Descent(mat X_train, mat Y_train);

double Get_func_value(mat w, mat x);

#endif