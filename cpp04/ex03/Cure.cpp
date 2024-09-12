#include "Cure.hpp"
#include <iostream>

Cure::Cure() : type("cure"){
	std::cout << "Cure default constructor called" << std::endl;
	return;
}

Cure::Cure(std::string const &type) : type(type){
	std::cout << "Cure type constructor called" << std::endl;
	return;
}

Cure::Cure(const Cure &src) : AMateria(), type("cure"){
	*this = src;
	std::cout << "Cure default constructor called" << std::endl;
	return;
}

Cure &Cure::operator=(const Cure &rhs){
	std::cout << "Cure assign constructor called" << std::endl;
	(void)rhs;
	return *this;
}

Cure::~Cure(){
	std::cout << "Cure default destructor called" << std::endl;
	return;
}

std::string const &Cure::getType(void) const{
	return (this->type);
}

Cure *Cure::clone() const{
	Cure *clone = new Cure();
	return (clone);
}
