#ifndef FILEMANAGMENT
#define FILEMANAGMENT
#include<iostream>
#include<algorithm>
#include <string>

#include"armadillo.hpp"
using namespace std;
using namespace arma;

//In this header file are functions that I will need to read and write data to and from files.

mat read_file(string file_path);

void save_file(mat output_matrix,string output_path);



#endif
