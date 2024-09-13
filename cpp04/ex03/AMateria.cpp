#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : type("Default"){
//	std::cout << "AMateria default constructor called" << std::endl;
	return;
}

AMateria::AMateria(std::string const &type) : type(type){
//	std::cout << "AMateria type constructor called" << std::endl;
	return;
}

AMateria::AMateria(const AMateria &src) : type(src.type){
//	std::cout << "AMateria copy constructor called" << std::endl;
	return;
}

AMateria &AMateria::operator=(const AMateria &rhs){
	(void)rhs;
//	std::cout << "AMateria assign operator called" << std::endl;
	return *this;
}

AMateria::~AMateria(){
	std::cout << "AMateria default destructor called" << std::endl;
	return;
}

std::string const &AMateria::getType(void) const{
	return (this->type);
}
