#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cassert>
#include <iostream>
#include <cmath>
#include <vector>
#include"Matrix.hpp"
#include"SparseVector.hpp"

template<class T> class Matrix; 
template<class T> class SparceVector; 

template <typename T>
class Vector
{
private:
	std::vector<T> mData; // data stored in standard vector of type T
	int mSize; // size of vector

public:
	Vector<T>(int size)
    {
        assert(size > 0);

        mSize = size;
        mData = std::vector<T>(size);

        for (auto element : mData)
        {
            element = 0.0; //Use auto to loop through all elements in mData and sets them to 0
        }
    }
    
	int size() const
    {
        return mSize;
    }

	T& operator[](int i)
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }

	T const& operator[] (int i)const
    {
        assert(i >= 0 && i < mSize);
        return mData[i];
    }


    // overloading the unary - operator
	Vector<T> operator-() const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = -mData[i];
        }
        return v;
    }


    // overloading the binary + operator
	Vector<T> operator+(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

    // overloading the binary - operator
	Vector<T> operator-(const Vector& v1) const
    {
        assert(mSize == v1.mSize);

        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

	// scalar multiplication
	Vector<T> operator*(double a) const
    {
        Vector<T> v(mSize);
        for (int i = 0; i < mSize; i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

	// p-norm method
	double CalculateNorm(int p = 2) const
    {
        double sum = 0.0;
        for (int i = 0; i < mSize; i++)
        {
            sum += pow(std::abs(mData[i]), p);
        }
        return pow(sum, 1.0 / ((double)(p)));
    }

    void Print(){
        int len = size();
        std::cout << "[";
        for(int i = 0; i < len; i++){
            std::cout << (*this)[i];

            if(i < len-1){ //Print commas between elements
                std::cout << ", ";
            }
        }
        std::cout << "]^T\n" << std::endl;
    }

    std::vector<T> const& getStorage(){ //Here we return a const version of mData, which means the output can be changed later. This is good if we want to use the vector in some downstream analysis, so we ensure the input isent changed. 
       return mData; 
    }

    /*
    The below methods are unnesecary as they are standard to std::vector
    
    // assignment operator
	Vector<T>& operator=(const Vector<T>& otherVector)
    {
        assert(mSize == otherVector.mSize);

        for (int i = 0; i < mSize; i++)
        {
            mData[i] = otherVector.mData[i];
        }
        return *this;
    }

    ~Vector()
    {
        delete[] mData;
    }

        // copy constructor
  Vector<T>(const Vector<T>& otherVector)
    {
        mSize = otherVector.size();

        mData = std::vector<T>(mSize);

        typename std::vector<T>::const_iterator c;

        for (int i = 0; i < mSize; i++)
        {
            mData.push_back(otherVector[i]); //We take the data from the given vector and copy it into the mData of the constructed vector
        }
    }

    */


};


#endif
