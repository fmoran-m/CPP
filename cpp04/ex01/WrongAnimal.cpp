#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
	return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs){
	std::cout << "WrongAnimal assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	WrongAnimal::makeSound(){
	std::cout << "An WrongAnimal class does not make sounds" << std::endl;
	return;
}

std::string WrongAnimal::getType(void) const{
	return this->type;
}
