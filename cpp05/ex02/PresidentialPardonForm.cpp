#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default", 25, 5, FALSE){
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), 25, 5, src.getSignBool()) {
	*this = src;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return (*this);
}

