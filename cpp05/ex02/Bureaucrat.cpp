#include "Bureaucrat.hpp"
#include <iostream>

#define	MIN_GRADE 150
#define	MAX_GRADE 1

Bureaucrat::Bureaucrat(void) : _name("Bureaucrat"), _grade(MIN_GRADE){
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > MIN_GRADE )
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat complete constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name){
	*this = src;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
	return;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	this->_grade = rhs._grade;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	return (*this);
}

void Bureaucrat::promotion(void){
	if (_grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	return;
}

void Bureaucrat::relegation(void){
	if (_grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	return;
}

std::string const Bureaucrat::getName(void) const{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("Bureaucrat grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("Bureaucrat grade too low");
}

void Bureaucrat::signForm(AForm &form){
	if (form.getSignBool())
	{
		std::cout << _name << " couldn`t sign " << form.getName() << " because it is alredy signed" << std::endl;
	}
	else
	{
		form.beSigned(*this);;
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	return;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &rhs){
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return out;
}
