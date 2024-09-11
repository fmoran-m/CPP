#include "Brain.hpp"
#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("AAnimal"){
	std::cout << "AAnimal default constructor called" << std::endl;
	return;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs){
	std::cout << "Assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	AAnimal::makeSound(){
	std::cout << "An AAnimal class does not make sounds" << std::endl;
	return;
}

Brain	*AAnimal::getBrain() const{
	return NULL;
}
