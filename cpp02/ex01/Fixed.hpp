#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed & src);
	Fixed(const int number);
	Fixed(const float number);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int		getRawBits(void) const;
	int		getPoint(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_n;
	static const int	_point = 8;
};

std::ostream	&operator<<(std::ostream &out, Fixed const &rhs);

#endif
