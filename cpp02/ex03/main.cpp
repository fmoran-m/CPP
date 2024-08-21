#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void){
	
	Point	a(-4.44f, -3.29f);
	Point	b(6.74f, -3.95f);
	Point	c(-3.82f, 5.92f);
	Point	point(1.52f, 1.55f);

	bool isInside = bsp(a, b, c, point);
	if (isInside == true)
		std::cout << "Point INSIDE the triangle" << std::endl;
	else
		std::cout << "Point OUTSIDE the triangle" << std::endl;
	return 0;
}
