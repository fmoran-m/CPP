#include "Point.hpp"

Point::Point(void) : x(0), y(0){
	//std::cout << "Empty constructor called" << std::endl;
	return;
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y){
	//std::cout << "Params constructor called" << std::endl;
	return;
}

Point::Point(const Point & src) : x(src.x), y(src.y){ //Cant initialize with *this = src because of const
	//std::cout << "Copy constructor called" << std::endl;
	return;
}

Point& Point::operator=(const Fixed &rhs){ //Cant reassign const values
	//std::cout << "Copy asignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

Point::~Point(void){
	//std::cout << "Destructor called" << std::endl;
	return;
}

Fixed const	&Point::getX(void) const{
	//std::cout << "getX" << std::endl;
	return this->x;
}

Fixed const	&Point::getY(void) const{
	//std::cout << "getY" << std::endl;
	return this->y;
}
