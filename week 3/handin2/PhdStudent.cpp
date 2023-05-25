#include "PhdStudent.hpp"
#include <cmath>

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime){
    //Constructor when info is known
    this->name = name; //As both input from metod and attribute is name we need this-> to spesify the atribute
    SetLibraryFines(0); //Phd do not pay fines
    tuition_fees = 0; // Graduates do not pay tuition
    this->fullTime = fullTime;
}


void PhdStudent::Print() const {
    //Print student information
    std::cout << "Name: " << name << std::endl;
    std::cout << name << " do not pay library fines because they are a PhD student." << std::endl;
    std::cout << name << " do not pay tuition fees because they are a PhD student." << std::endl;
    std::cout << "Is " << name << " a full time student: " << fullTime << " (1 = full time, 0 = not full time)" << "\n" <<std::endl;
}

double PhdStudent::MoneyOwed() const{
    //phd students do not pay tuition or library fines so they always owe nothing
    return 0;
}