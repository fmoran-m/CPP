#include "Ice.hpp"
#include <iostream>

Ice::Ice() : type("ice"){
	std::cout << "Ice default constructor called" << std::endl;
	return;
}

Ice::Ice(std::string const &type) : type(type){
	std::cout << "Ice type constructor called" << std::endl;
	return;
}

Ice::Ice(const Ice &src) : AMateria(), type("ice"){
	*this = src;
	std::cout << "Ice default constructor called" << std::endl;
	return;
}

Ice &Ice::operator=(const Ice &rhs){
	std::cout << "Ice assign constructor called" << std::endl;
	(void)rhs;
	return *this;
}

Ice::~Ice(){
	std::cout << "Ice default destructor called" << std::endl;
	return;
}

std::string const &Ice::getType(void) const{
	return (this->type);
}

Ice *Ice::clone() const{
	Ice *clone = new Ice();
	return (clone);
}
