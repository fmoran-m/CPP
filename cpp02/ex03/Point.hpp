#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
public:
	Point();
	Point(Fixed x, Fixed y);
	Point(const Point &);
	Point &operator=(const Point &rhs);
	~Point();
private:
	Fixed const x;
	Fixed const y;
};
#endif
