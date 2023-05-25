#include<iostream>
#include<algorithm>
#include <string>

#include"armadillo.hpp"
#include"NearestNeighbours.hpp"
#include"file_managment.hpp"
#include"file_managment.cpp"

using namespace std;
using namespace arma;

int main(int argc, char* argv[]){
    Neares_Neighbours("dataX.dat", "dataXtest.dat", "dataY.dat");
    return 0;
}

mat euclidean_distance(mat test, mat train){
    //takes a 1 dimensional matrix (vector) and calculate the distance from that point to all points in the test data. The outputs a matrix with all the distances.
    mat distances(train.n_rows,1); //initiate matrix for distances

    for(int i = 0; i < train.n_rows; i++){ // loops through all rows in teaining data
        distances(i) = norm(test.row(0) - train.row(i), 2);// We find the euclidean distance between the test point and the current row in train. We then save the distance at position i in distances.
    }
    return distances;
}

int calculate_label(mat distances, int K = 5){
    //This function takes the distance and label matrix sort it in ascending order and calculates a label based on the K closest neighbours

    // Sort the matrix based on the first column
    uvec sorted_indices = sort_index(distances.col(0)); // we find the indicies when we sort based on the first column (distances)
    //uvec is an unsigned vector from armadillo

    // Rearrange all columns based on the sorted indices
    mat sorted_dists = distances.rows(sorted_indices);

    //We need to sort like this instead of just using sort() because we want the connection between the clumns to stay the same, otherwise distances will be sorted but the labels will not also be sorted acordingly. 

    int label_sum; 
    label_sum = sum((sorted_dists.col(1)).head(K)); // we sum up the labels from the K nearest neighbours

    if( label_sum > 0){ // more 1 labels than -1 labels so test observation is label 1.
        //cout << "Label sum is: " << label_sum << " Therefore the observation is labeled: 1" << endl;
        return int(1);
    }
    else { // more -1 labels than 1 labels so test observation is label -1. OBS this is also true if K is even and label count is tie.
        //cout << "Label sum is: " << label_sum << " Therefore the observation is labeled: -1" << endl;
        return int(-1);
    }
}



void Neares_Neighbours(string X_train_path, string X_test_path, string Y_train_path){
    //First we use the inputted paths to load the test and training data
    mat X_train; mat X_test; mat Y_train;
    X_train = read_file(X_train_path); X_test = read_file(X_test_path); Y_train = read_file(Y_train_path);

    mat labels(X_test.n_rows, 1); //initiate a vector to store the labels

    for(int i = 0; i < X_test.n_rows; i++){ //A loop that runs through all point in our test data
        mat temp_dists;
        temp_dists = euclidean_distance(X_test.row(i), X_train); // caluculate distance from current test point to all points in train

        temp_dists = join_rows(temp_dists,Y_train); //we merge the distances with the labels, we do this to keep track of the labels when we sort the distances.

        //cout << "Not sorted distances: \n" << temp_dists <<endl;

        labels(i) = calculate_label(temp_dists);
    }
    //cout << "The labels are: \n " << labels << endl;
    save_file(labels,"NN.dat"); //write label vector to NN.dat
}