#include <iostream>
#include <cstring>
#include <algorithm>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern(void) {
//	std::cout << "Intern default constructor called" << std::endl;
	return;
}

Intern::Intern(Intern const &src) {
//	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
	return;
}

Intern::~Intern(void) {
//	std::cout << "Intern destructor called" << std::endl;
	return;
}

Intern &Intern::operator=(Intern const &rhs) {
//	std::cout << "Intern copy constructor called" << std::endl;
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}

AForm *Intern::makeForm(std::string request, std::string target){

	AForm *forms[3];

	forms[0] = new ShrubberyCreationForm(target);
	forms[1] = new RobotomyRequestForm(target);
	forms[2] = new PresidentialPardonForm(target);

	request = _formatRequest(request);
	try{
		int index = _checkRequest(forms, request);
		AForm *newForm = forms[index]->clone();
		for (int i = 0; i < 3; i++)
			delete (forms[i]);
		return (newForm);
	}catch (std::exception &e){
		for (int i = 0; i < 3; i++)
			delete (forms[i]);
		std::cout << "Error: " << e.what() << std::endl;
		return (NULL);
	}
}

int Intern::_checkRequest(AForm **forms, std::string request){
	for (int i = 0; i < 3; i++){
		if (forms[i]->getRequest() == request)
			return(i);
	}
	throw FormNotFoundException();
	return (-1);
}

std::string Intern::_formatRequest(std::string request){
  std::transform(request.begin(), request.end(), request.begin(), ::tolower);
    return request;
}

const char *Intern::FormNotFoundException::what(void) const throw(){
	return ("Form not found");
}
