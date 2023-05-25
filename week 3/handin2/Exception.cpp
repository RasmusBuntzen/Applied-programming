#include <iostream>
#include "Exception.hpp"

Exception::Exception(std::string tagString, std::string probString){
    //constructor
    mTag = tagString;
    mProblem = probString;
}

Exception::Exception(){
    //Default constructor
    mTag = "UnknownProblem";
    mProblem = "An unknown exception has been thrown";
}

void Exception::PrintDebug() const{ //Metod that prints the exception
    std::cerr << "** Error ("<<mTag<<") **\n";
    std::cerr << "Problem: " << mProblem << "\n\n";
}