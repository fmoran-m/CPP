#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5, FALSE){
	this->_target = "target";
//	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, FALSE){
	this->_target = target;
//	std::cout << "PresidentialPardonForm target constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), 25, 5, src.getSignBool()) {
	*this = src;
//	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
//	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	this->_target = rhs.getTarget();
	this->setSignBool(rhs.getSignBool());
//	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const{
	return (this->_target);
}

void PresidentialPardonForm::executeThis(void) const{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return;
}

PresidentialPardonForm *PresidentialPardonForm::clone(void){
	PresidentialPardonForm *clone = new PresidentialPardonForm(*this);
	return (clone);
}

std::string PresidentialPardonForm::getRequest(void) const{
	return ("presidential pardon");
}
