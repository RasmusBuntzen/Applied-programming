#include "GraduateStudent.hpp"
#include <cmath>

GraduateStudent::GraduateStudent(){
    //Default constructor
        //Default constructor
    name = "Unknown";
    tuition_fees = 0.0;
    SetLibraryFines(0.0);
}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime){
    //Constructor when info is known
    this->name = name; //As both input from metod and attribute is name we need this-> to spesify the atribute
    SetLibraryFines(fines);
    tuition_fees = 0; // Graduates do not pay tuition
    this->fullTime = fullTime;
}
void GraduateStudent::Print() const {
    //Print student information
    std::cout << "Name: " << name << std::endl;
    std::cout << "Total library fines: " << GetLibraryFines() << std::endl;
    std::cout << name << " do not pay tuition because they are a graduate student." << std::endl;
    std::cout << "Is " << name << " a full time student: " << fullTime << " (1 = full time, 0 = not full time)" << "\n" <<std::endl;
}

double GraduateStudent::MoneyOwed() const{
    return GetLibraryFines(); //they dont pay tuition
}