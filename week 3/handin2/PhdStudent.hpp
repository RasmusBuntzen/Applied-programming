#ifndef SUBMISSION_PHDSTUDENT_HPP_
#define SUBMISSION_PHDSTUDENT_HPP_

#include "GraduateStudent.hpp"

class PhdStudent : public GraduateStudent {
public:
	PhdStudent(std::string name, double fines, double fees, bool fullTime);
	virtual double MoneyOwed() const;

	virtual void Print() const; //I added this so i can print student information easily
};



#endif /* SUBMISSION_PHDSTUDENT_HPP_ */
