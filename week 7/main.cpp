#include <iostream>
#include <string>

#include "./handin4/NearestNeighbours.cpp"
#include "./armadillo.hpp"
using namespace std;
using namespace arma;

int main(int argc, char* argv[]){
    Neares_Neighbours("./handin4/dataX.dat", "./handin4/dataXtest.dat", "./handin4/dataY.dat");
    //Neares_Neighbours("./Xtrain_small.txt", "./Xtrain_small.txt", "./Ytrain_small.txt");
    return 0;
}