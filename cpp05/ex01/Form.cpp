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
	std::cout << "Form complete constructor called" << std::endl;
	if (signGrade < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (signGrade > MIN_GRADE)
		throw Form::GradeTooLowException();
	return;
}

Form::Form(Form const &src) : _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
	return;
}

Form &Form::operator=(Form const &rhs) {
	std::cout << "Form copy constructor called" << std::endl;
	if (this == &rhs){
		return (*this);
	}
	this->_signBool = rhs._signBool;
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
	return ("Form grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw(){
	return ("Form grade too low");
}

std::ostream	&operator<<(std::ostream &out, Form const &rhs){
	out << rhs.getName() << ", form grade " << rhs.getSignGrade();
	return out;
}

void Form::beSigned(Bureaucrat &bur){
	if (bur.getGrade() < this->_signGrade)
		throw Form::GradeTooLowException();
	if (bur.signForm(this) == TRUE)
		this->_signBool = TRUE;
	return;
}
