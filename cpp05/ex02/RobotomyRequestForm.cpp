#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default", 72, 45, FALSE){
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), 72, 45, FALSE) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}

