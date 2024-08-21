#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
public:
	Point();
	Point(Fixed x, Fixed y);
	Point(const Point &);
	Point &operator=(const Fixed &rhs);
	~Point();

	Fixed const &getX(void)const;
	Fixed const &getY(void)const;
private:
	Fixed const x;
	Fixed const y;
};
#endif
