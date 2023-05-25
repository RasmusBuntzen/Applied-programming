#ifndef SUBMISSION_GRADUATESTUDENT_HPP_
#define SUBMISSION_GRADUATESTUDENT_HPP_

#include "Student.hpp"

class GraduateStudent : public Student {
private:

public:
	GraduateStudent();
	GraduateStudent(std::string name, double fines, double fees, bool fullTime);
	bool fullTime;
	virtual double MoneyOwed() const;

	virtual void Print() const; //I added this so i can print student information easily

};



#endif /* SUBMISSION_GRADUATESTUDENT_HPP_ */
