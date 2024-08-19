#include "Point.hpp"

Point::Point(void) : x(0), y(0){
	return;
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y){
	return;
}

Point::Point(const Point & src){

	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return;
}

Point& Point::operator=(const Point & rhs){

	return *this;
}

Point::~Point(void){
	return;
}
