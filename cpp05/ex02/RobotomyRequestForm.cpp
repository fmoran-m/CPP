#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45, FALSE){
	this->_target = "target";
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, FALSE){
	this->_target = target;
	std::cout << "RobotomyRequestForm target constructor called" << std::endl;
	return;
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
	if (this == &rhs){
		return (*this);
	}
	this->_target = rhs.getTarget();
	this->setSignBool(rhs.getSignBool());
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const{
	return (this->_target);
}

void RobotomyRequestForm::executeThis(void) const{
	int n;

	n = rand();
	if (n % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed" << std::endl;
	return;
}
