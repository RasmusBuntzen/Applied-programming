#include <iostream>
#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob)
    : Exception("FileNotOpen", prob)
{
    Exception("FileNotOpen", prob);
} //We need this syntax as Exception does not have a default constructor so we have to explicitly set it