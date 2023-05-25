#include <iostream>
#include "OutOfRangeException.hpp"


OutOfRangeException::OutOfRangeException(std::string prob)
    : Exception("OutOfRange", prob)
{
    Exception("OutOfRange", prob);
} //We need this syntax as Exception does not have a default constructor so we have to explicitly set it
