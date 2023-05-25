#include<iostream>
#include<algorithm>
#include <string>

#include"armadillo.hpp"
#include"file_managment.hpp"

using namespace std;
using namespace arma;

mat read_file(string file_path){
    mat A; //Initiate matrix
    A.load(file_path); //load the file
    return A;
}

void save_file(mat output_matrix, string output_path){
    output_matrix.save(output_path,arma::raw_ascii); //raw_ascii is the format we save the data in (I.E no formatting)
}