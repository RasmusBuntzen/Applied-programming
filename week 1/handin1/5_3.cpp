#include "5_3.h"
#include <iostream>

void swap_pointer(double *a, double *b);
void swap_ref(double &a, double &b);

void swap_pointer(double *a, double *b){
    std::cout << "Pointers:\n";
    std::cout << "a = " << *a << " ,b = " << *b << "\n";
    double temp_b = *b; //temporarely stores *b
    *b = *a; //b value is stored with a value (both memory adresses are not changed only the value of adress b)
    *a = temp_b; //a is stored with b value (again the adresses are not changed only the actual value in memory is changed)
    std::cout << "Swap!" << "\n";
    std::cout << "a = " << *a << " ,b = " << *b << "\n";
}

void swap_ref(double &a, double &b){
    std::cout << "\nReferences:\n";
    std::cout << "a = " << a << " ,b = " << b << "\n";
    double temp_b = b; // As we here are working with references we can just swap the values of the variables without thinking of their place in memory
    b = a;
    a = temp_b;
    std::cout << "Swap!" << "\n";
    std::cout << "a = " << a << " ,b = " << b << "\n";
}