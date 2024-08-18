#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(const int number){
	std::cout << "Int constructor called" << std::endl;
	this->_n = number << this->_point;
	return;
}

Fixed::Fixed(const float number){

	int i = 0;
	int exp = 1;

	std::cout << "Float constructor called" << std::endl;

	while (i < this->_point)
	{
		exp *= 2;
		i++;
	}
	this->_n = roundf(number * exp);
	return;
}

Fixed& Fixed::operator=(const Fixed & rhs){

	std::cout << "Copy asignment operator called" << std::endl;
	this->_n = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const{
	return this->_n;	
}

void	Fixed::setRawBits(int const raw){
	this->_n = raw;
}

float	Fixed::toFloat(void) const{

	float	exp = 1;
	float	raw = float(_n);
	float	f_number;


	for(int i = 0; i < this->_point; i++)
		exp *= 2;
	f_number = raw / exp;
	return (f_number);
}

int	Fixed::toInt(void) const{

	return(this->_n >> _point);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs){

	out << rhs.toFloat();

	return out;
}
