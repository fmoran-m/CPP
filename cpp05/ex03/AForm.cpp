#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void) : _name("AForm"), _signGrade(MIN_GRADE),
	_executeGrade(MIN_GRADE), _signBool(FALSE)
{
//	std::cout << "AForm default constructor called" << std::endl;
	return;
}

AForm::AForm(std::string name, int signGrade, int executeGrade, bool signBool)
: _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _signBool(signBool)
{
	if (signGrade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (signGrade > MIN_GRADE)
		throw AForm::GradeTooLowException();
//	std::cout << "AForm complete constructor called" << std::endl;
	return;
}

AForm::AForm(AForm const &src) : _name(src._name), _signGrade(src._signGrade), _executeGrade(src._executeGrade)
{
	*this = src;
//	std::cout << "AForm copy constructor called" << std::endl;
	return;
}

AForm &AForm::operator=(AForm const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	this->_signBool = rhs._signBool;
//	std::cout << "AForm copy constructor called" << std::endl;
	return (*this);
}

AForm::~AForm(void) {
//	std::cout << "AForm destructor called" << std::endl;
	return;
}

std::string const AForm::getName(void) const{
	return(_name);
}

int AForm::getSignGrade(void) const{
	return(_signGrade);
}

int AForm::getExecuteGrade(void) const{
	return(_executeGrade);
}

bool AForm::getSignBool(void) const{
	return(_signBool);
}

const char *AForm::GradeTooHighException::what(void) const throw(){
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what(void) const throw(){
	return ("Grade is too low");
}

const char *AForm::AlreadySignedException::what(void) const throw(){
	return ("is already signed");
}

const char *AForm::SignatureFailureException::what(void) const throw(){
	return ("Form not signed");
}

void AForm::beSigned(Bureaucrat &bur){
	if (this->getSignBool())
		throw AForm::AlreadySignedException();
	if (bur.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signBool = TRUE;
	return;
}

void AForm::setSignBool(bool signBool){
	this->_signBool = signBool;
	return;
}

void AForm::execute(Bureaucrat const &executor) const{
	if (this->getSignBool() == FALSE){
		throw AForm::SignatureFailureException();
	}
	if (this->getExecuteGrade() < executor.getGrade()){
		throw Bureaucrat::GradeTooLowException();
	}
	this->executeThis();
	return;
}

std::ostream	&operator<<(std::ostream &out, AForm const &rhs){
	std::cout << rhs.getName() << ", form sign grade " << rhs.getSignGrade() <<
		", form execute grade " << rhs.getExecuteGrade() << ", sign bool "
		<< rhs.getSignBool();
	return out;
}

class GradeTooHighException : public std::exception{
	public:
		virtual const char *what() const throw();
};
