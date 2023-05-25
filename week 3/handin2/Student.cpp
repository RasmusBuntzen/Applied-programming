#include "Student.hpp"
#include <cmath>
#include <cassert>

Student::Student(){
    //Default constructor
    name = "Unknown";
    tuition_fees = 0.0;
    library_fines = 0.0;
}

Student::Student(std::string name, double fines, double fees){
    //Constructor that sets all variables
    this->name = name; //As both input from metod and attribute is name we need this-> to spesify the atribute
    library_fines = fines;
    tuition_fees = fees;
}

void Student::Print() const {
    //Print student information
    std::cout << "Name: " << name << std::endl;
    std::cout << "Total library fines: " << library_fines << std::endl;
    std::cout << "Total tuition owed: " << tuition_fees << "\n" << std::endl;

}

double Student::MoneyOwed() const{
    //Default is library fines + tuition fees
    return library_fines + tuition_fees;
}

void Student::SetLibraryFines(double amount){
    //Library fines is privat so we make this method to set it
    //assert(amount <= 0); // amount must not be negative (OBS code cheker does not like assert -_-)
    if(amount < 0){
        library_fines = -amount; //If use puts in a negative amount the library fines are set |amount|
    }
    else{
    library_fines = amount; //If positive amount is inputted
    }
}

double Student::GetLibraryFines() const{
    //Extract library_fines
    return library_fines;
}