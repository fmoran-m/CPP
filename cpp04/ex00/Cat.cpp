#include "Cat.hpp"
#include <iostream>

Cat::Cat() : type("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
	return;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat::Cat(const Cat &src) : Animal(){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return;
}

Cat &Cat::operator=(const Cat &rhs){
	std::cout << "Cat assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound(){
	std::cout << this->type << ": Meow!! Meow!!" << std::endl;
	return;
}

std::string Cat::getType(void) const{
	return this->type;
}
