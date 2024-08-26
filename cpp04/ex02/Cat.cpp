#include "Cat.hpp"
#include <iostream>

Cat::Cat() : type("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
	return;
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat::Cat(const Cat &src) : AAnimal(){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Cat &Cat::operator=(const Cat &rhs){
	std::cout << "Assign operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound(){
	std::cout << this->type << ": Meow!! Meow!!" << std::endl;
	return;
}
