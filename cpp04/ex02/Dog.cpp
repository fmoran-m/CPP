#include "Dog.hpp"
#include <iostream>

Dog::Dog() : type("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
	return;
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
	return;
}

Dog::Dog(const Dog &src) : AAnimal(){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Dog &Dog::operator=(const Dog &rhs){
	std::cout << "Assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound(){
	std::cout << this->type << ": Woof!! Woof!!" << std::endl;
	return;
}

Brain	*Dog::getBrain() const{
	return (brain);
}
