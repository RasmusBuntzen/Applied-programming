#include "./handin3/Matrix.hpp"
#include "./handin3/SparseVector.hpp"
#include "./handin3/Vector.hpp"

#include <iostream>

int main(int argc, char* argv[]){
    /* Matrix and vector
    std::cout << "Matrix tests:\n";
    std::cout << "Constructor. Should be 0,0,0,0" << std::endl;
    Matrix<int> A = Matrix<int>(2,2);
    A.Print();
    std::cout << "GetNumberOf..(). Should be 2x2)" << std::endl;
    std::cout << "Above matrix has dimensions " << A.GetNumberOfRows() << " x " << A.GetNumberOfColumns() << "\n" << std::endl; //Test GetNumberOf..

    std::cout << "() and = operator. Should be 1,2,3,4" << std::endl;
    A(0,0) = 1; A(0,1) = 2; A(1,0) = 3; A(1,1) = 4; // test () and = operator
    Matrix<int> B = A;
    B.Print();

    std::cout << "Copy Constructor. Should be 1,2,3,4" << std::endl;
    Matrix<int> C = Matrix<int>(A); //Copy constructor
    C.Print();

    std::cout << "Binary -. Should be 0,0,0,0" << std::endl;
    C = A-B;
    C.Print();

    std::cout << "Unary -. Should be -1,-2,-3,-4" << std::endl;
    C = -A;
    C.Print();

    std::cout << "Binary +. Should be 2,4,6,8" << std::endl;
    C = A+A;
    C.Print();

    std::cout << "Vector tests:" << std::endl;

    std::cout << "Constructor. Should be 0,0,0,0" << std::endl;
    Vector<int> V = Vector<int>(4);
    V.Print();

    std::cout << "[] operator. Should be 1,2,3,4" << std::endl;
    V[0] = 1; V[1] = 2; V[2] = 3; V[3] = 4;
    V.Print();

    Vector<int> W = Vector<int>(V);
    std::cout << "Copy Constructor. Should be 1,2,3,4" << std::endl;
    W.Print();

    std::cout << "Size. Should be 4\n";
    std::cout << "Above vector has size: " << V.size() << "\n" << std::endl;

    Vector<int> Q = Vector<int>(4);
    Q = V;
    std::cout << "= operator. Should be 1,2,3,4" << std::endl;
    Q.Print();

    Q = -V;
    std::cout << "Unary - operator. Should be -1,-2,-3,-4" << std::endl;
    Q.Print();

    Q = V-V;
    std::cout << "Binary - operator. Should be 0,0,0,0" << std::endl;
    Q.Print();

    Q = V+V;
    std::cout << "Binary + operator. Should be 2,4,6,8" << std::endl;
    Q.Print();

    Q = V*5;
    std::cout << "* operator. Should be 5,10,15,20" << std::endl;
    Q.Print();

    std::cout << "CalculateNorm. Should be 27.3861" << std::endl;
    std::cout << "Above vector has a norm of " << Q.CalculateNorm() << "\n" << std::endl;

    Vector<int> v = Vector<int>(2);
    Vector<int> res(2) ;
    v[0] = 1; v[1] = 2;

    std::cout << "Matrix and vector multiplication tests:\n";

    std::cout << "v*m. Should be 7,10" << std::endl;
    res = v*A;
    res.Print();

    std::cout << "m*v. Should be 5,11" << std::endl;
    res = A*v;
    res.Print();
    
    */
   SparseVector<double> A(10);

   A.setValue(2,2);
   A.setValue(5,5);
   A.setValue(3,-3);
   A.setValue(5,0);
   
    std::cout << "A has dimensions: " << A.size() << " (Should be 10)\n" << std::endl;
    std::cout << "A has " << A.nonZeroes() << " non zero elements. (Should be 3)\n" << std::endl;
    std::cout << "Indicies and values: (Should be [2,3,5], [2,3,8])\n" << std::endl;
    A.Print();
    std::cout << "Index 5 has value: " << A.getValue(5) << " (Should be 8)\n" << std::endl;
    std::cout << "The third stored non zero entry has index: " << A.indexNonZero(2) << " (Should be 5)\n" << std::endl;
    std::cout << "The third stored non zero entry has value: " << A.valueNonZero(2) << " (Should be 8)\n" << std::endl;


    SparseVector<double> B;
    std::cout << "B has dimensions: " << B.size() << " (Should be 0)\n" << std::endl;
    std::cout << "B has " << B.nonZeroes() << " non zero elements. (Should be 0)\n" << std::endl;

    SparseVector<double> C(10);
    C.setValue(1,2.3);
    C.setValue(3,3.3);
    A.Print();
    C.Print();
    std::cout << "result\n";
    C -= A;
    std::cout << "+= test (Should be [1,2,3,5] [3,2,6,8]):\n";
    C.Print();
    
    SparseVector<double> D(10);
    D.setValue(4,9);
    D.setValue(5,7);
    D -= A;
    std::cout << "-= test (Should be [2,3,4,5] [-2,-3,9,-1]):\n";
    D.Print();

    D = A;
    
    SparseVector<double> x(2);
    x.setValue(1,1);

    Matrix<double> A2(2,2);
    A2(0,0) = 1; A2(0,1) = 2; A2(1,0) = 3; A2(1,1) = 4;

    std::cout << "Matrix*SparseVector (Should be [2,4]):\n";
    Vector<double> V = Vector<double>(2);
    V = A2*x;
    V.Print();


    SparseVector<double> x1(5);
    x1.setValue(2,5); x1.setValue(4,3);

    Matrix<double> A1(5,2);
    A1(0,1) = 1; A1(1,0) = 1; A1(1,1) = 3; A1(2,0) = 2; A1(2,1) = 8; A1(4,0) = 5; A1(4,1) = 4;

    std::cout << "SparseVector*Matrix (Should be [25,52]):\n";
    V = x1*A1;
    V.Print();


    SparseVector<double> x2(5); SparseVector<double> x3(5); SparseVector<double> x4(5);
    x2.setValue(0,1); x2.setValue(2,5); x2.setValue(4,1);
    x3.setValue(1,4); x3.setValue(3,2); x3.setValue(4,3);

    std::cout << "binary + test (Should be [0,1,2,3,4] [1,4,5,2,4]):\n";
    x4=x2+x3;
    x4.Print();

    std::cout << "binary - test (Should be [0,1,2,3,4] [1,-4,5,-2,-2]):\n";
    x4= x2-x3;
    x4.Print();

    //std::cout << "binary - test (Should be [2,3,4,5] [2,3,-9,1]):\n";
    //A=A-D;
    //A.Print();
    
    return 0;
}
