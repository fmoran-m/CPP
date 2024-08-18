#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _n(0){

	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed(){

	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed & src){

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed& Fixed::operator=(const Fixed & rhs){

	std::cout << "Copy asignment operator called" << std::endl;
	this->_n = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_n;	
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
}
