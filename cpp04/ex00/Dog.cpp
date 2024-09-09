#include "Dog.hpp"
#include <iostream>

Dog::Dog() : type("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
	return;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	return;
}

Dog::Dog(const Dog &src) : Animal(){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return;
}

Dog &Dog::operator=(const Dog &rhs){
	std::cout << "Dog assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound(){
	std::cout << this->type << ": Woof!! Woof!!" << std::endl;
	return;
}

std::string Dog::getType(void) const{
	return this->type;
}
