#include "Point.hpp"

Fixed	ft_abs(Fixed n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

Fixed calculateTriangleArea(Point const a, Point const b, Point const c){

	Fixed	p1, p2, p3;
	Fixed	n1, n2, n3;

	p1 = a.getX() * b.getY();
	p2 = a.getY() * c.getX();
	p3 = b.getX() * c.getY();

	n1 = c.getX() * b.getY();
	n2 = c.getY() * a.getX();
	n3 = b.getX() * a.getY();

	Fixed	det = (ft_abs(p1 + p2 + p3 - n1 - n2 - n3) * Fixed(0.5f));
	return (det);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){

	Fixed triangleArea;
	Fixed subArea1, subArea2, subArea3;

	triangleArea = calculateTriangleArea(a, b, c);

	subArea1 = calculateTriangleArea(a, b, point);
	if (subArea1 == 0)
		return (false);

	subArea2 = calculateTriangleArea(a, c, point);
	if (subArea2 == 0)
		return (false);

	subArea3 = calculateTriangleArea(b, c, point);
	if (subArea2 == 0)
		return (false);

	if ((subArea1 + subArea2 + subArea3) > triangleArea)
		return (false);

	return (true);
}

