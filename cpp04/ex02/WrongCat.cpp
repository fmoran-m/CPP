#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : type("WrongCat"){
	std::cout << "WrongCat default constructor called" << std::endl;
	return;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(){
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = src;
	return;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs){
	std::cout << "WrongCat assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound(){
	std::cout << this->type << ": Meow!! Meow!!" << std::endl;
	return;
}

std::string WrongCat::getType(void) const{
	return this->type;
}
