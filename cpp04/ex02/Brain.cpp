#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
	return;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Brain	&Brain::operator=(const Brain &rhs){
	std::cout << "Assign operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

std::string	Brain::getIdea(int index) const{
	return (this->ideas[index]);
}

void	Brain::setIdea(int index, std::string newIdea){
	this->ideas[index] = newIdea;
}
