#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &);
	Fixed(const int number);
	Fixed(const float number);
	Fixed &operator=(const Fixed &rhs); //La referencia se debe a que cuando
										//se hacen muchas asignaciones, hasta 
										//que el compilador no acaba de procesar 
										//la expresión, los valores no se actualizan.
										//En el caso de a = b = c, b no cambiaría hasta terminar de evaluar la expresión. 
										//Sin embargo, al devolver la referencia, es posible acceder al objeto que se acaba
										//de actualizar sin depender de que el compilador devuelva nada. Si dependieramos de copias
										//o de no devolver nada (void), b se quedaría desactualizado y no podría ser evaluado por a
										//correctamente
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
