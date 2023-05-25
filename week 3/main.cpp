#include "./handin2/ComplexNumber.cpp"
#include "./handin2/ComplexNumber.hpp"
#include "./handin2/CalculateExponential.cpp"
#include "./handin2/CalculateExponential.hpp"
#include "./handin2/Matrix2x2.cpp"
#include "./handin2/Matrix2x2.hpp"
#include "./handin2/Student.cpp"
#include "./handin2/Student.hpp"
#include "./handin2/GraduateStudent.cpp"
#include "./handin2/GraduateStudent.hpp"
#include "./handin2/PhdStudent.cpp"
#include "./handin2/PhdStudent.hpp"
#include "./handin2/Exercise82.hpp"
#include "./handin2/Exception.cpp"
#include "./handin2/Exception.hpp"
#include "./handin2/OutOfRangeException.cpp"
#include "./handin2/OutOfRangeException.hpp"
#include "./handin2/FileNotOpenException.cpp"
#include "./handin2/FileNotOpenException.hpp"

#include <iostream>
#include <fstream>
#include <algorithm> //for use of min

//Below func is need in exersice 9.1
void ReadFile(const std::string& fileName, double x[], double y[],int num_elements_in_input_array) //Function that takes a file name and two vectors, put x any y values into x and y vectors
{
    std::ifstream read_file(fileName.c_str()); //Open files
    if (read_file.is_open() == false){
        throw (FileNotOpenException("File can’t be opened. Input directiory is possibly not valid.")); //Throw an exception if file does not open
    }

    std::string line; 
    int num_lines = 0;
    while (std::getline(read_file, line)) { //Getline extracts each line 1 ata time, we increment num_lines 1 pr line to count how many lines are in the file
        ++num_lines;
    }

    if(num_elements_in_input_array < num_lines){
        throw(OutOfRangeException("Given arrays are not large enough to hold all data from input file!")); //Throw exception if x can not hold all x values from the file
    }

    for (int i=0; i<num_lines; i++){ //copy values into x and y
        read_file >> x[i] >> y[i];
    }

    read_file.close(); //close file

    std::cout << fileName <<" read successfully\n";
}
int main(int argc, char* argv[]){
    /*
#pragma ComplexNumber test
    //set complex number with only real part
    ComplexNumber a = ComplexNumber(10.5);
    std::cout << "Real part: "<<a.GetRealPart() << " , Imaginary part: " << a.GetImaginaryPart() << "\n";
    std::cout << "Real part: "<< RealPart(a) << " , Imaginary part: " << ImaginaryPart(a) << "\n";

    ComplexNumber b = 0;
    //test copy construct 
    std::cout << "Real part: "<< RealPart(b) << " , Imaginary part: " << ImaginaryPart(b) << "\n";
    b = ComplexNumber(a);
    std::cout << "Real part: "<< RealPart(b) << " , Imaginary part: " << ImaginaryPart(b) << "\n";

    //CalculateConjugate test
    ComplexNumber c = ComplexNumber(2,5);
    std::cout << "Conjugate of " << c << " is " << c.CalculateConjugate() << "\n";

    //Set.Conjugate test
    c.SetConjugate();
    std::cout << "Real part: "<< RealPart(c) << " , Imaginary part: " << ImaginaryPart(c) << "\n";
#pragma endregion

    ComplexNumber **A;
    int ARows = 3,ACols = 3;
    A = new ComplexNumber*[ARows];
    for (int i = 0; i < ARows; ++i) 
        {
            A[i] = new ComplexNumber[ACols];
        }
    // Initialize B with values
    A[0][0] = ComplexNumber(2,3); A[0][1] = ComplexNumber(0,0); A[0][2] = ComplexNumber(0,0);
    A[1][0] = ComplexNumber(0,0); A[1][1] = ComplexNumber(4,5); A[1][2] = ComplexNumber(0,0);
    A[2][0] = ComplexNumber(0,0); A[2][1] = ComplexNumber(0,0); A[2][2] = ComplexNumber(6,7);

    ComplexNumber **res;
    res = new ComplexNumber*[ARows];
    for (int i = 0; i < ARows; ++i) 
        {
            res[i] = new ComplexNumber[ACols];
        }

    CalculateExponential(A,50,res);
    for (int i = 0; i < 3; ++i) {
        delete[] A[i];
        delete[] res[i];
    }
    delete[] A;
    delete[] res;
    
    Matrix2x2 A; //default constructor test
    A.Print(); // Print test
    Matrix2x2 B = Matrix2x2(1,2,3,4); //4 entry constructor test
    B.Print();
    Matrix2x2 C = Matrix2x2(B); //Copy constructor test
    C.Print();
    std::cout << "Determinant of C is: " << C.CalcDeterminant() << "\n" << std::endl; //CalcDeterminant test
    Matrix2x2 D = C.CalcInverse(); // CalcInverse test
    D.Print();
    D = B; //= overload test
    D.Print();
    D = -D; //- overload test
    D.Print();
    D = B+B; //+ overload test
    D.Print();
    D = D-D; //- overload test
    D.Print();
    B.MultScalar(5); //MultScalar test
    B.Print();
    std::cout << "Element 00 of B is: " << B.Getval00() << "\n" << std::endl; //Getval test
    
   Student A = Student(); //Default constructor test
   A.Print();

   Student B = Student("Rasmus Buntzen",10,10000); //3 variable constructor test
    B.Print();
    std::cout << "In total " << B.name << "owes: " << B.MoneyOwed() << "\n" << std::endl;

    B.SetLibraryFines(0); //SetLibraryFines test
    std::cout << "Rasmus Buntzen's libraby fines are now: " << B.GetLibraryFines() << "\n" << std::endl; //GetLibrayFines test

    GraduateStudent C = GraduateStudent(); //Default GraduateStudent constructor test
    C.Print();

    GraduateStudent D = GraduateStudent("Signe Frederiksen",1000,10,1); //GraduateStudent Constructor test
    D.Print();

    std::cout << "In total " << D.name << " owes: " << D.MoneyOwed() << "\n" << std::endl; //Graduate MoneyOwes test

    PhdStudent E = PhdStudent("Krølle",1000,10000,0); //PhdStudent constructor test
    E.Print();

    std::cout << "In total " << E.name << " owes: " << E.MoneyOwed() << "\n" << std::endl; //Graduate MoneyOwes test
    

    auto A = -5; //Here we use auto to set the var type (here int)
    std::cout << "Absolute value of "<< A << " is " << CalcAbs<int>(A) << "\n" << std::endl;
    */

    try {
        //To test it we can try to change size of x or y to < 10 (number of lines in xy.dat), or given an unvalid file namewhen calling ReadFile()

        double x[10], y[10]; // create vectors to store x and y values

        int min_xy_size = std::min(sizeof(x)/sizeof(double),sizeof(y)/sizeof(double)); //sizeof return how many bytes x fills, so we divide by the size of double to get num of elements.
        ReadFile("xy.dat", x, y,min_xy_size); //We need to also input the size of x
    } 
    catch (const OutOfRangeException& error) {
        std::cerr << "Caught OutOfRangeException: ";
        error.PrintDebug();
    } 
    catch (const FileNotOpenException& error) {
        std::cerr << "Caught FileNotOpenException: ";
        error.PrintDebug();
    } 
    catch (const Exception& error) {
        std::cerr << "Caught generic Exception: ";
        error.PrintDebug();
    } 
    
    return 0;
}
