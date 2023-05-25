#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include"Vector.hpp"
#include"SparseVector.hpp"

template<class T> class Vector; 
template<class T> class SparceVector; 

template <typename T> //Allows user to choose what the elements type should be
class Matrix
{
private:
	std::vector<T> mData; // entries of matrix
	int mNumRows, mNumCols; // dimensions

public:


	Matrix<T>(int numRows, int numCols)
    {
        assert(numRows > 0);
        assert(numCols > 0);

        mNumRows = numRows;
        mNumCols = numCols;

        mData = std::vector<T>(mNumRows*mNumCols);

        std::fill(mData.begin(), mData.end(), 0.0); //we can use std::fill to easily fill a vector with a certain value

    }

	int GetNumberOfRows() const
    {
        return mNumRows;
    }

	int GetNumberOfColumns() const
    {
        return mNumCols;
    }

	T& operator()(int i, int j)
    {
        assert(i >= 0);
        assert(i < mNumRows);
        assert(j >= 0);
        assert(j < mNumCols);

        return mData[i*GetNumberOfColumns()+j];  //A matrix M that is n*m can be flatten into a Vector V, the index M[i][j] = V[i*m+j]
    }

	T const& operator()(int i, int j) const
    {
        assert(i >= 0);
        assert(i < mNumRows);
        assert(j >= 0);
        assert(j < mNumCols);

        return mData[i*GetNumberOfColumns()+j];
    }



	Matrix<T> operator-() const // unary -
    {
        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = -mData[i*GetNumberOfColumns()+j];
            }
        }
        return mat;
    }

	Matrix<T> operator+(const Matrix<T>& m1) const // binary +
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = mData[i*GetNumberOfColumns()+j] + m1.mData[i*GetNumberOfColumns()+j];
            }
        }
        return mat;
    }

	Matrix<T> operator-(const Matrix<T>& m1) const // binary -
    {
        assert(mNumRows == m1.mNumRows);
        assert(mNumCols == m1.mNumCols);

        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = mData[i*GetNumberOfColumns()+j] - m1.mData[i*GetNumberOfColumns()+j];
            }
        }
        return mat;
    }

	// scalar multiplication
	Matrix<T> operator*(double a) const
    {
        Matrix<T> mat(mNumRows, mNumCols);
        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mat(i,j) = a*mData[i*GetNumberOfColumns()+j];
            }
        }
        return mat;
    }

    void Print() const { //easily prints the matrix
        int rows = GetNumberOfRows();
        int cols = GetNumberOfColumns();

        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                std::cout << (*this)(j, k) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::vector<T> const& getStorage(){ //Here we return a const version of mData, which means the output can be changed later. This is good if we want to use the vector in some downstream analysis, so we ensure the input isent changed. 
       return mData; 
    }

    /*
    Below method is unnecesary as it is standard for std::vector
    // overloaded assignment operator
	Matrix<T>& operator=(const Matrix<T>& otherMatrix)
    {
        assert(mNumRows == otherMatrix.mNumRows);
        assert(mNumCols == otherMatrix.mNumCols);

        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mData[i*GetNumberOfColumns()+j] = otherMatrix.mData[i*GetNumberOfColumns()+j];
            }
        }
        return *this;
    }

    std::vector does it's own memory managment
	~Matrix<T>()
    {
        for (int i = 0; i < mNumRows; i++)
        {
            delete[] mData[i];
        }
        delete[] mData;
    }

    // copy constructor
	Matrix<T>(const Matrix<T>& otherMatrix)
    {
        mNumRows = otherMatrix.mNumRows;
        mNumCols = otherMatrix.mNumCols;

        mData = std::vector<T>(mNumRows*mNumCols);

        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mData[i*mNumCols+j] = otherMatrix.mData[i*mNumCols+j];
            }
        }
    }
    
    */

//Matrix multiplication 
    Matrix<T> operator*(const Matrix<T>& m1) const // matrix multiplication
    {
        assert(mNumCols == m1.mNumRows);

        int resultRows = mNumRows;
        int resultCols = m1.mNumCols;
        Matrix<T> result(resultRows, resultCols);

        for (int i = 0; i < resultRows; i++)
        {
            for (int j = 0; j < resultCols; j++)
            {
                T sum = 0;
                for (int k = 0; k < mNumCols; k++)
                {
                    sum += mData[i * mNumCols + k] * m1.mData[k * m1.mNumCols + j];
                }
                result(i, j) = sum;
            }
        }

        return result;
    }

    Matrix<T> transpose() const
    {
        Matrix<T> transposed(mNumCols, mNumRows);
        for (int i = 0; i < mNumRows; ++i) {
            for (int j = 0; j < mNumCols; ++j) {
                transposed(j, i) = (*this)(i, j);
            }
        }
        return transposed;
    }
}; // class Matrix


//matrix-vector multiplications
template <typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
    int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);

	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

template <typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);

	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}

/*
template<class T>
void sparseToMatrix(SparseVector<T> const& x, unsigned int rows, unsigned int cols,Matrix<T>& M){
	unsigned int dimension = x.size();
	//unsigned int cols = dimension / rows; //from dimesnions of x we can calculate the number of cols needed in the matrix

	//Matrix<T> M = Matrix<T>(rows,cols); //initiate matrix of correct size

	for (unsigned int i = 0; i < x.nonZeroes(); ++i) { //loop through non zero elements in x
	unsigned int M_i_index = x.indexNonZero(i) / cols;  //convertion from index in Sparse vector to index in matrix
	unsigned int M_j_index = x.indexNonZero(i) % cols;
	M(M_i_index,M_j_index) = x.valueNonZero(i);
	}
}

template<class T>
Vector<T> matrixToVector(Matrix<T> const& M){
    Vector<T> V(M.GetNumberOfColumns()*M.GetNumberOfRows());
    for (int i = 0; i < M.GetNumberOfRows(); i++) {
        for (int j = 0; j < M.GetNumberOfColumns(); j++) {
            // Access the element at row i and column j
            V[i*M.GetNumberOfColumns()+j] = M(i, j);
        }
    }
    return V;
}

*/

#endif
