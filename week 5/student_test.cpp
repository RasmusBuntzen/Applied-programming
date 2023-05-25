#include <iostream>
#include <cstdlib>
#include "./handin3/Matrix.hpp"
#include "./handin3/SparseVector.hpp"
#include "./handin3/Vector.hpp"


int main(int argc, char* argv[]) {
    std::cout << "Testing SparseVector methods.\n";
    std::cout << "Constructor test:\n";
    SparseVector<double> x = SparseVector<double>(10);
    std::cout << "Succeeded.\n";
    std::cout << "Printing test x: " // << x << "\n";
		<< x.getValue(0) << " "
		<< x.getValue(1) << " "
		<< x.getValue(2) << " "
		<< x.getValue(3) << " "
		<< x.getValue(4) << " "
		<< x.getValue(5) << " "
		<< x.getValue(6) << " "
		<< x.getValue(7) << " "
		<< x.getValue(8) << " "
		<< x.getValue(9) << "\n";

    x.setValue(0, 1.1);
    x.setValue(1, 8.9);
    x.setValue(2, 3.4);
    x.setValue(8, 5.2);
    std::cout << "Vector setting test: " 
		<< x.getValue(0) << " "
		<< x.getValue(1) << " "
		<< x.getValue(2) << " "
		<< x.getValue(3) << " "
		<< x.getValue(4) << " "
		<< x.getValue(5) << " "
		<< x.getValue(6) << " "
		<< x.getValue(7) << " "
		<< x.getValue(8) << " "
		<< x.getValue(9) << "\n";
    std::cout << "Vector retrieving test1: " << x.getValue(2) << "\n";
    std::cout << "Vector retrieving test2: " << x.getValue(3) << "\n";
	
	x.setValue(3, 2.1);
    std::cout << "Vector pos_updating retrieving test: " << x.getValue(3) << "\n";
    std::cout << "Vector getting entry test1 x[3]: " << x.getValue(3) << "\n";
    std::cout << "Vector getting entry test2 x[5]: " << x.getValue(5) << "\n";
    SparseVector <double> y = SparseVector<double>(x);
    std::cout << "Vector copy constructor test y[3]: " << y.getValue(3) << "\n";
	std::cout << "Vector copy constructor test y[5]: " << y.getValue(5) << "\n";

    y.setValue(8, -2.1);
    y.setValue(5, 3.7);
	std::cout << "Vector set value test y[8]: " << y.getValue(8) << "\n";
	std::cout << "Vector set value test y[5]: " << y.getValue(5) << "\n";
    std::cout << "Vector size test: " << x.size() << "\n";

	SparseVector <double> z = SparseVector<double>(x.size()); //failed
    std::cout << "Vector empty constructor test: "  
		<< z.getValue(0) << " " 
		<< z.getValue(1) << " "
		<< z.getValue(2) << " "
		<< z.getValue(3) << " "
		<< z.getValue(4) << " "
		<< z.getValue(5) << " "
		<< z.getValue(6) << " "
		<< z.getValue(7) << " "
		<< z.getValue(8) << " "
		<< z.getValue(9) << "\n";
    std::cout << "Vector empty size test: " << z.size() << "\n";

    std::cout << "Testing nonZero count 1: " << x.nonZeroes() << "\n";
    std::cout << "Testing nonZero count 2: " << z.nonZeroes() << "\n";

    std::cout << "Testing 0th non-zero index: " << x.indexNonZero(0) << "\n";
    std::cout << "Testing 2nd non-zero index: " << x.indexNonZero(2) << "\n";
    //std::cout << "Testing 9th non-zero index: " << x.indexNonZero(9) << "\n";
    std::cout << "Testing 0th non-zero value: " << x.valueNonZero(0) << "\n";
    std::cout << "Testing 2nd non-zero value: " << x.valueNonZero(2) << "\n";
    //std::cout << "Testing 9th non-zero value: " << x.valueNonZero(9) << "\n";

    std::cout << "Currently, vector x is : " 
		<< x.getValue(0) << " "
		<< x.getValue(1) << " "
		<< x.getValue(2) << " "
		<< x.getValue(3) << " "
		<< x.getValue(4) << " "
		<< x.getValue(5) << " "
		<< x.getValue(6) << " "
		<< x.getValue(7) << " "
		<< x.getValue(8) << " "
		<< x.getValue(9) << "\n";
	std::cout << "Currently, vector y is : " 
		<< y.getValue(0) << " "
		<< y.getValue(1) << " "
		<< y.getValue(2) << " "
		<< y.getValue(3) << " "
		<< y.getValue(4) << " "
		<< y.getValue(5) << " "
		<< y.getValue(6) << " "
		<< y.getValue(7) << " "
		<< y.getValue(8) << " "
		<< y.getValue(9) << "\n";


	z = x-y;
	// z.print_indices();
	// z.print_values();
    std::cout << "Sparse vector binary - test1: " 
		<< z.getValue(0) << " " 
		<< z.getValue(1) << " "
		<< z.getValue(2) << " "
		<< z.getValue(3) << " "
		<< z.getValue(4) << " "
		<< z.getValue(5) << " "
		<< z.getValue(6) << " "
		<< z.getValue(7) << " "
		<< z.getValue(8) << " "
		<< z.getValue(9) << "\n";
	
	z = y-x;
	// z.print_indices();
	// z.print_values();
    std::cout << "Sparse vector binary - test2: "
		<< z.getValue(0) << " " 
		<< z.getValue(1) << " "
		<< z.getValue(2) << " "
		<< z.getValue(3) << " "
		<< z.getValue(4) << " "
		<< z.getValue(5) << " "
		<< z.getValue(6) << " "
		<< z.getValue(7) << " "
		<< z.getValue(8) << " "
		<< z.getValue(9) << "\n";

	z=x+y;
    std::cout << "Sparse vector binary + test: "
		<< z.getValue(0) << " " 
		<< z.getValue(1) << " "
		<< z.getValue(2) << " "
		<< z.getValue(3) << " "
		<< z.getValue(4) << " "
		<< z.getValue(5) << " "
		<< z.getValue(6) << " "
		<< z.getValue(7) << " "
		<< z.getValue(8) << " "
		<< z.getValue(9) << "\n";

    x+=y;
    std::cout << "Sparse vector += test: "
		<< x.getValue(0) << " "
		<< x.getValue(1) << " "
		<< x.getValue(2) << " "
		<< x.getValue(3) << " "
		<< x.getValue(4) << " "
		<< x.getValue(5) << " "
		<< x.getValue(6) << " "
		<< x.getValue(7) << " "
		<< x.getValue(8) << " "
		<< x.getValue(9) << "\n";

    x-=y;
    std::cout << "Sparse vector -= test: "
		<< x.getValue(0) << " "
		<< x.getValue(1) << " "
		<< x.getValue(2) << " "
		<< x.getValue(3) << " "
		<< x.getValue(4) << " "
		<< x.getValue(5) << " "
		<< x.getValue(6) << " "
		<< x.getValue(7) << " "
		<< x.getValue(8) << " "
		<< x.getValue(9) << "\n";
	x-=y;
    std::cout << "Sparse vector -= test2: "
		<< x.getValue(0) << " "
		<< x.getValue(1) << " "
		<< x.getValue(2) << " "
		<< x.getValue(3) << " "
		<< x.getValue(4) << " "
		<< x.getValue(5) << " "
		<< x.getValue(6) << " "
		<< x.getValue(7) << " "
		<< x.getValue(8) << " "
		<< x.getValue(9) << "\n";
	x+=y;

	z=x+y;
    std::cout << "Sparse vector binary + test: "
		<< z.getValue(0) << " " 
		<< z.getValue(1) << " "
		<< z.getValue(2) << " "
		<< z.getValue(3) << " "
		<< z.getValue(4) << " "
		<< z.getValue(5) << " "
		<< z.getValue(6) << " "
		<< z.getValue(7) << " "
		<< z.getValue(8) << " "
		<< z.getValue(9) << "\n";
	
	std::srand(0);
	int ARows = 9;
	int ACols = y.size();
	Matrix<double> A = Matrix<double>(ARows, ACols);
	for (int i=0; i<ARows; i++) {
		for (int j=0; j<ACols; j++) {
			double new_value = (double) std::rand() / RAND_MAX;
			if (new_value * 100 > 90) {
				double new_value2 = (double) std::rand() / RAND_MAX;
				A(i,j) = new_value - new_value2;
			}
		}
	}
    // A(0,0) = 1.0;
    // A(1,1) = 1.0;
    // A(2,2) = 2.0;
    // A(3,3) = 2.0;
    // A(4,4) = 1.0;
    // A(5,5) = 1.0;
    // A(6,6) = 1.0;
    // A(8,8) = 3.0;
    std::cout << "Matrix A: \n" 
		<< A(0,0) << " " << A(0,1) << " " << A(0,2) << " " << A(0,3) << " " << A(0,4) << " " << A(0,5) << " " << A(0,6) << " " << A(0,7) << " " << A(0,8) << " " << A(0,9) << "\n"
		<< A(1,0) << " " << A(1,1) << " " << A(1,2) << " " << A(1,3) << " " << A(1,4) << " " << A(1,5) << " " << A(1,6) << " " << A(1,7) << " " << A(1,8) << " " << A(1,9)  << "\n"
		<< A(2,0) << " " << A(2,1) << " " << A(2,2) << " " << A(2,3) << " " << A(2,4) << " " << A(2,5) << " " << A(2,6) << " " << A(2,7) << " " << A(2,8) << " " << A(2,9)  << "\n"
		<< A(3,0) << " " << A(3,1) << " " << A(3,2) << " " << A(3,3) << " " << A(3,4) << " " << A(3,5) << " " << A(3,6) << " " << A(3,7) << " " << A(3,8) << " " << A(3,9)  << "\n"
		<< A(4,0) << " " << A(4,1) << " " << A(4,2) << " " << A(4,3) << " " << A(4,4) << " " << A(4,5) << " " << A(4,6) << " " << A(4,7) << " " << A(4,8) << " " << A(4,9)  << "\n"
		<< A(5,0) << " " << A(5,1) << " " << A(5,2) << " " << A(5,3) << " " << A(5,4) << " " << A(5,5) << " " << A(5,6) << " " << A(5,7) << " " << A(5,8) << " " << A(5,9)  << "\n"
		<< A(6,0) << " " << A(6,1) << " " << A(6,2) << " " << A(6,3) << " " << A(6,4) << " " << A(6,5) << " " << A(6,6) << " " << A(6,7) << " " << A(6,8) << " " << A(6,9)  << "\n"
		<< A(7,0) << " " << A(7,1) << " " << A(7,2) << " " << A(7,3) << " " << A(7,4) << " " << A(7,5) << " " << A(7,6) << " " << A(7,7) << " " << A(7,8) << " " << A(7,9)  << "\n"
		<< A(8,0) << " " << A(8,1) << " " << A(8,2) << " " << A(8,3) << " " << A(8,4) << " " << A(8,5) << " " << A(8,6) << " " << A(8,7) << " " << A(8,8) << " " << A(8,9)  << "\n";
    std::cout << "times vector y: "
		<< y.getValue(0) << " "
		<< y.getValue(1) << " "
		<< y.getValue(2) << " "
		<< y.getValue(3) << " "
		<< y.getValue(4) << " "
		<< y.getValue(5) << " "
		<< y.getValue(6) << " "
		<< y.getValue(7) << " "
		<< y.getValue(8) << " "
		<< y.getValue(9) << "\n";

	Vector<double> c = A*y; // 1.88263 0 0 0 0 0 2.86414 0 3.23498
    std::cout << "is A*y: " // 1.1 8.9 6.8 4.2 0 3.7 0 0 -6.3 
		<< c[0] << " "
		<< c[1] << " "
		<< c[2] << " "
		<< c[3] << " "
		<< c[4] << " "
		<< c[5] << " "
		<< c[6] << " "
		<< c[7] << " "
		<< c[8] << "\n";
    
	int BRows = y.size();
	int BCols = 5;
	Matrix<double> B = Matrix<double>(BRows, BCols);
	for (int i=0; i<BRows; i++) {
		for (int j=0; j<BCols; j++) {
			double new_value = (double) std::rand() / RAND_MAX;
			if (new_value * 100 > 90) {
				double new_value2 = (double) std::rand() / RAND_MAX;
				B(i,j) = new_value - new_value2;
			}
		}
	}
	std::cout << "Matrix B: \n" 
		<< B(0,0) << " " << B(0,1) << " " << B(0,2) << " " << B(0,3) << " " << B(0,4) << "\n"
		<< B(1,0) << " " << B(1,1) << " " << B(1,2) << " " << B(1,3) << " " << B(1,4) << "\n"
		<< B(2,0) << " " << B(2,1) << " " << B(2,2) << " " << B(2,3) << " " << B(2,4) << "\n"
		<< B(3,0) << " " << B(3,1) << " " << B(3,2) << " " << B(3,3) << " " << B(3,4) << "\n"
		<< B(4,0) << " " << B(4,1) << " " << B(4,2) << " " << B(4,3) << " " << B(4,4) << "\n"
		<< B(5,0) << " " << B(5,1) << " " << B(5,2) << " " << B(5,3) << " " << B(5,4) << "\n"
		<< B(6,0) << " " << B(6,1) << " " << B(6,2) << " " << B(6,3) << " " << B(6,4) << "\n"
		<< B(7,0) << " " << B(7,1) << " " << B(7,2) << " " << B(7,3) << " " << B(7,4) << "\n"
		<< B(8,0) << " " << B(8,1) << " " << B(8,2) << " " << B(8,3) << " " << B(8,4) << "\n"
    	<< B(9,0) << " " << B(9,1) << " " << B(9,2) << " " << B(9,3) << " " << B(9,4) << "\n";

    // B(0,0) = 2.0;
    // B(1,1) = 2.0;
    // B(2,2) = 1.0;
	// B(4,4) = 1.0;
    // std::cout << "Matrix B: \n"; // << B << "\n";
    std::cout << "times vector y: \n";// << y << "\n";
	Vector<double> d = y*B;  // 3.29741 0 0 0.947927 4.98103
    std::cout << "is y*B: "  // 2.2 17.8 3.4 0 0
		<< d[0] << " "
		<< d[1] << " "
		<< d[2] << " "
		<< d[3] << " "
		<< d[4] << "\n";

    return 0;
}