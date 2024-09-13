#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure"){
//	std::cout << "Cure default constructor called" << std::endl;
	return;
}

Cure::Cure(std::string const &type) : AMateria(type){
//	std::cout << "Cure type constructor called" << std::endl;
	return;
}

Cure::Cure(const Cure &src) : AMateria(src.type){
//	std::cout << "Cure copy constructor called" << std::endl;
	return;
}

Cure &Cure::operator=(const Cure &rhs){
//	std::cout << "Cure assign constructor called" << std::endl;
	(Cure)rhs;
	return *this;
}

Cure::~Cure(){
//	std::cout << "Cure default destructor called" << std::endl;
	return;
}

Cure *Cure::clone() const{
	Cure *clone = new Cure(this->getType());
	return (clone);
}

void Cure::use(std::string const &name) const{
	std::cout << "* heals " << name << "'s wounds *" << std::endl;
}
