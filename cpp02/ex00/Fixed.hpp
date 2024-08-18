#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed & rhs);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int					_n;
	static const int	_point = 8;
	
};
#endif
