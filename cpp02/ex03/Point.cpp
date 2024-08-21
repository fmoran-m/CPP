#include "Point.hpp"

Point::Point(void) : x(0), y(0){
	return;
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y){
	return;
}

Point::Point(const Point & src) : x(src.x), y(src.y){
	//std::cout << "Copy constructor called" << std::endl;
	return;
}

Point& Point::operator=(const Fixed &rhs){
	(void)rhs;
	return (*this);
}

Point::~Point(void){
	return;
}

Fixed const	&Point::getX(void) const{
	return this->x;
}

Fixed const	&Point::getY(void) const{
	return this->y;
}
