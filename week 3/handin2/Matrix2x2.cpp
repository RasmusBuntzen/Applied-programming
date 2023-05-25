#include "Matrix2x2.hpp"
#include <cmath>
#include <cassert>

void Matrix2x2::Print() const {
    //Prints the matrix
    std::cout << val00 << " , " << val01 << std::endl;
    std::cout << val10 << " , " << val11 << "\n" << std::endl;
}


Matrix2x2::Matrix2x2(){
    //Default constructor that enetiates all values to 0.0
    val00 = 0.0;
	val01 = 0.0;
	val10 = 0.0;
	val11 = 0.0;
}

Matrix2x2::Matrix2x2(const Matrix2x2& other){
    //A copy constructor that takes a Matrix2x2 and retruns a Matrix2x2 with same elements
    val00 = other.Getval00();
	val01 = other.Getval01();
	val10 = other.Getval10();
	val11 = other.Getval11();
}

Matrix2x2::Matrix2x2(double a, double b, double c, double d){
    val00 = a;
	val01 = b;
	val10 = c;
	val11 = d;
}

double Matrix2x2::CalcDeterminant() const{
    //calculates the determinant of the matrix
    return val00*val11 - val01*val10;
}

Matrix2x2 Matrix2x2::CalcInverse() const{
    //return the inverse matrix as a new matrix
    double det = CalcDeterminant();
    assert(det != 0); //If determinant is 0 the matrix has no inverse
    
    return Matrix2x2(val11*(1/det), -val01*(1/det),-val10*(1/det),val00*(1/det));
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z){
    //Overload the = operator so we can set matricies equal to each other
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;
    val11 = z.val11;
    return *this;
}

Matrix2x2 Matrix2x2::operator-() const{
    //Overload - operator that changes sign on all element of input
    return Matrix2x2(-val00, -val01, -val10, -val11);
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const{
    //Overload + so we can elementwise add matricies
    return Matrix2x2(val00+z.val00, val01+z.val01, val10+z.val10, val11+z.val11);
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const{
    //Overload - so we can elemntwise subtract matricies
    return Matrix2x2(val00-z.val00, val01-z.val01, val10-z.val10, val11-z.val11);
}

void Matrix2x2::MultScalar(double scalar){
    //Multiplies all entries by scalar
    val00 = val00*scalar;
    val01 = val01*scalar;
    val10 = val10*scalar;
    val11 = val11*scalar;
}