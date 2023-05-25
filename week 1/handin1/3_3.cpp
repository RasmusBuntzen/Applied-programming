#include "3_3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

void implicit_Euler(int n);

void implicit_Euler(int n){
    assert(n > 1);

    std::vector<double> x; //initiate vector for x and y coordinates
    std::vector<double> y;
    x.resize(n); //change size of the vectors to the size spesified by the user
    y.resize(n);

    // Calculate the step size
    double h = 1.0 / (n-1);

    x[0] = 0.0; //initiate strt values
    y[0] = 1.0;

    for(int step = 1; step < n; step++){ //loop through the specified number of times (n-1) and fill in x and y vector
        x[step] = step * h;
        y[step] = y[step-1] / (1+h);
    }
    std::ofstream write_file("xy.dat"); // open or cretae xy.dat
    assert(write_file.is_open()); //check if the file actuallt is open
    for(int step = 0; step < n; step++){ // loop through all elements of x any y and write them to xy.dat
        write_file << x[step] << "," << y[step] << "\n";
        assert(write_file.good()); //check if write to file is good
    }
    write_file.close();
    std::cout << "see xy.dat\n";
}