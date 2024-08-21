#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Constructor & Destructor

Fixed::Fixed(void) : _n(0){

	//std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed(){

	//std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed & src){

	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::Fixed(const int number){
	//std::cout << "Int constructor called" << std::endl;
	this->_n = number << this->_point;
	return;
}

Fixed::Fixed(const float number){

	int i = 0;
	int exp = 1;

	//std::cout << "Float constructor called" << std::endl;

	while (i < this->_point)
	{
		exp *= 2;
		i++;
	}
	this->_n = roundf(number * exp);
	return;
}

//Setters and getters

int	Fixed::getRawBits(void) const{
	//std::cout << "getRawBits called" << std::endl;
	return this->_n;	
}

void	Fixed::setRawBits(int const raw){
	//std::cout << "setRawBits called" << std::endl;
	this->_n = raw;
}

int	Fixed::getPointExp(void) const{

	int exp = 1;

	for (int i = 0; i < this->_point; i++)
		exp*= 2;
	return (exp);
}

//Converters

float	Fixed::toFloat(void) const{

	float	exp = 1;
	float	raw = float(_n);
	float	fNumber;


	//std::cout << "toFloat called" << std::endl;
	for(int i = 0; i < this->_point; i++)
		exp *= 2;
	fNumber = raw / exp;
	return (fNumber);
}

int	Fixed::toInt(void) const{

	//std::cout << "toInt called" << std::endl;
	return(this->_n >> _point);
}

//Operators

Fixed& Fixed::operator=(const Fixed & rhs){

	//std::cout << "Copy asignment operator called" << std::endl;
	this->_n = rhs.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &rhs) const{

	//std::cout << "> operator called" << std::endl;
	if (this->_n <= rhs.getRawBits())
		return false;
	return true;
}

bool Fixed::operator<(const Fixed &rhs) const{

	//std::cout << "< operator called" << std::endl;
	if (this->_n >= rhs.getRawBits())
		return false;
	return true;
}

bool Fixed::operator>=(const Fixed &rhs) const{

	//std::cout << ">= operator called" << std::endl;
	if (this->_n < rhs.getRawBits())
		return false;
	return true;
}

bool Fixed::operator<=(const Fixed &rhs) const{

	//std::cout << "<= operator called" << std::endl;
	if (this->_n > rhs.getRawBits())
		return false;
	return true;

}

bool Fixed::operator==(const Fixed &rhs) const{

	//std::cout << "== operator called" << std::endl;
	if (this->_n != rhs.getRawBits())
		return false;
	return true;
}

bool Fixed::operator!=(const Fixed &rhs) const{

	//std::cout << "!= operator called" << std::endl;
	if (this->_n == rhs.getRawBits())
		return false;
	return true;
}

Fixed Fixed::operator+(const Fixed &rhs) const{

	//std::cout << "+ operator called" << std::endl;
	
	Fixed	result;
	result.setRawBits(this->_n + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const{

	//std::cout << "- operator called" << std::endl;
	
	Fixed	result;
	result.setRawBits(this->_n - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const{

	//std::cout << "* operator called" << std::endl;
	
	Fixed	result;
	result.setRawBits((this->_n * rhs.getRawBits()) / this->getPointExp());
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const{

	//std::cout << "/ operator called" << std::endl;
	
	Fixed	result;
	result.setRawBits((this->_n / rhs.getRawBits()) * this->getPointExp());
	return (result);
}

Fixed	&Fixed::operator++(void){

	//std::cout << "++ Preincrement operator called" << std::endl;
	
	this->setRawBits(this->_n + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void){

	//std::cout << "-- Predecrement operator called" << std::endl;
	
	this->setRawBits(this->_n - 1);
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed newInstance;

	//std::cout << "++ Postincrement operator called" << std::endl;
	
	newInstance.setRawBits(this->getRawBits());
	this->setRawBits(this->_n + 1);
	return (newInstance);
}

Fixed	Fixed::operator--(int){
	Fixed newInstance;

	//std::cout << "-- Postdecrement operator called" << std::endl;
	
	newInstance.setRawBits(this->getRawBits());
	this->setRawBits(this->_n - 1);
	return (newInstance);
}

//Max min member function

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs){

	//std::cout << "Min function" << std::endl;
	
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs){

	//std::cout << "Max function" << std::endl;
	
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed const &Fixed::min(const Fixed &lhs, const Fixed &rhs){

	//std::cout << "Min const function" << std::endl;
	
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed const &Fixed::max(const Fixed &lhs, const Fixed &rhs){

	//std::cout << "Max const function" << std::endl;

	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

//Stream operators

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs){

	//std::cout << "Stdout stream << called" << std::endl;

	out << rhs.toFloat();
	return out;
}
