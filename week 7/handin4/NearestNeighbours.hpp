#ifndef NN
#define NN
#include<iostream>
#include<algorithm>
#include <string>

#include"armadillo.hpp"

using namespace std;
using namespace arma;

void Neares_Neighbours(string X_train_path, string X_test_path, string Y_train_path);

mat euclidean_distance(mat test, mat train);

int calculate_label(mat distances, int K);


#endif
