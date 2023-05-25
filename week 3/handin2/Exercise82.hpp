#ifndef SUBMISSION_EXERCISE82_HPP_
#define SUBMISSION_EXERCISE82_HPP_

template<typename T>
T CalcAbs(T val) {
	T result = val; //makes a var of type T (same type as input)
	if(result >= 0){ //input is positive
		return result;
	}
	else{ //input is negative
		return -result;
	}
}

#endif /* SUBMISSION_EXERCISE82_HPP_ */
