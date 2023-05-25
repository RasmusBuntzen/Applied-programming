#include "ComplexNumber.hpp"
#include <cmath>

#pragma region Given code from book
// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart*mRealPart+
        mImaginaryPart*mImaginaryPart);
}
// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}
// Method for raising complex number to the power n
// using De Moivre’s theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument*n;
    double real_part = mod_of_result*cos(arg_of_result);
    double imag_part = mod_of_result*sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,
const ComplexNumber& z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
    output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
    // z.mImaginaryPart < 0.0
    // Replace + with minus sign
    output << "- " << -z.mImaginaryPart << "i)";
    }
        return output;
}
#pragma endregion
//------------Excersise starts from here------------------
double ComplexNumber::GetRealPart() const{
    //As real part i private, we make a function that returns the real part
    return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const{
    //return imaginary part
    return mImaginaryPart;
}

double RealPart(const ComplexNumber& z){
    //friend function that takes a ComplexNumber class as input and returns the real part
    return z.mRealPart;
}

double ImaginaryPart(const ComplexNumber& z){
    //Same as above, it just return imaginary part
    return z.mImaginaryPart;
}

ComplexNumber::ComplexNumber(const ComplexNumber& z){
    //Here we overwrite the copy construct.
    //This mean when we give ComplexNumber() a ComplexNumber class, it returns ComplexNumber class with same real and imaginary parts as the input
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
}

ComplexNumber::ComplexNumber(double real){
    //Here we can specify a real number as a complex number where the complex part is 0
    mRealPart = real;
    mImaginaryPart = 0.0;
}

ComplexNumber ComplexNumber::CalculateConjugate() const{
    //Return a complex number that is the conjugat of the input
    //z = x +yi, has a conjugat z_conj = x - yi
    return ComplexNumber(mRealPart,- mImaginaryPart);
}

void ComplexNumber::SetConjugate(){
    //Takes a complexnumber and sets it to its own conjugat
    mImaginaryPart = -mImaginaryPart;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const{
    //Later we will need to multiply complex numbers, so we create the method here
    ComplexNumber W;
    W.mRealPart = (mRealPart*z.mRealPart) - (mImaginaryPart*z.mImaginaryPart);
    W.mImaginaryPart = mImaginaryPart*z.mRealPart + mRealPart*z.mImaginaryPart;

    return W;
}


// Overloading the / (division) operator
ComplexNumber ComplexNumber::operator/(const ComplexNumber& z) const{
    //Later we will need to multiply complex numbers, so we create the method here
    ComplexNumber W;
    W.mRealPart = (mRealPart*z.mRealPart + mImaginaryPart*z.mImaginaryPart) / (z.mRealPart*z.mRealPart + z.mImaginaryPart * z.mImaginaryPart);
    W.mImaginaryPart =(mImaginaryPart*z.mRealPart - mRealPart*z.mImaginaryPart) / (z.mRealPart*z.mRealPart + z.mImaginaryPart * z.mImaginaryPart);

    return W;
}