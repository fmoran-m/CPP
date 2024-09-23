#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void) : _name("Form"), _signGrade(MIN_GRADE),
	_executeGrade(MIN_GRADE), _signBool(FALSE)
{
	std::cout << "Form default constructor called" << std::endl;
	return;
}

Form::Form(std::string name, int signGrade, int executeGrade, bool signBool)
: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _signBool(signBool)
{
	if (signGrade < MAX_GRADE || executeGrade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (signGrade > MIN_GRADE || executeGrade > MIN_GRADE)
		throw Form::GradeTooLowException();
	std::cout << "Form complete constructor called" << std::endl;
	return;
}

Form::Form(Form const &src) : _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	*this = src;
	std::cout << "Form copy constructor called" << std::endl;
	return;
}

Form &Form::operator=(Form const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	this->_signBool = rhs._signBool;
	std::cout << "Form copy constructor called" << std::endl;
	return (*this);
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
	return;
}

std::string const Form::getName(void) const{
	return(_name);
}

int Form::getSignGrade(void) const{
	return(_signGrade);
}

int Form::getExecuteGrade(void) const{
	return(_executeGrade);
}

bool Form::getSignBool(void) const{
	return(_signBool);
}

const char *Form::GradeTooHighException::what(void) const throw(){
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw(){
	return ("Grade too low");
}

void Form::beSigned(Bureaucrat &bur){
	if (bur.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signBool = TRUE;
	return;
}

std::ostream	&operator<<(std::ostream &out, Form const &rhs){
	std::cout << rhs.getName() << ", form sign grade " << rhs.getSignGrade() <<
		", form execute grade " << rhs.getExecuteGrade() << ", sign bool "
		<< rhs.getSignBool();
	return out;
}
