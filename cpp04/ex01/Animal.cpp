#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal"){
	std::cout << "Animal default constructor called" << std::endl;
	return;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Animal &Animal::operator=(const Animal &rhs){
	std::cout << "Assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	Animal::makeSound(){
	std::cout << "An Animal class does not make sounds" << std::endl;
	return;
}

Brain	*Animal::getBrain() const{
	return NULL;
}
