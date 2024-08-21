#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &);
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();

	Fixed &operator=(const Fixed &rhs);
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	static Fixed 	&min(Fixed &lhs, Fixed &rhs);
	static Fixed	&max(Fixed &lhs, Fixed &rhs);
	static Fixed const	&min(const Fixed &lhs, const Fixed &rhs);
	static Fixed const	&max(const Fixed &lhs, const Fixed &rhs);

	int		getRawBits(void) const;
	int		getPoint(void) const;
	int		getPointExp(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:

	int					_n;
	static const int	_point = 8;
	
};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);


#endif
