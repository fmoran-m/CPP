#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void){
	
	Point	a(3, 3);
	Point	b(6, 8);
	Point	c(8, 2);
	Point	point(4, 4);

	bool isInside = bsp(a, b, c, point);
	if (isInside == true)
		std::cout << "Point INSIDE the triangle" << std::endl;
	else
		std::cout << "Point OUTSIDE the triangle" << std::endl;
	return 0;
}
