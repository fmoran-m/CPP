#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default", 145, 137, FALSE) {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), 145, 137, FALSE){
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}

