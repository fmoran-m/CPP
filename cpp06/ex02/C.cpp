#include "C.hpp"
#include <iostream>
C::C(void) {
	//std::cout << "C default constructor called" << std::endl;
}
C::C(C const &src) {
	//std::cout << "C copy constructor called" << std::endl;
	*this = src;
	return;
}
C::~C(void) {
	//std::cout << "C destructor called" << std::endl;
	return;
}
C &C::operator=(C const &rhs) {
	//std::cout << "C copy constructor called" << std::endl;
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}
