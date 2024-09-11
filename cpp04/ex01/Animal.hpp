#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include "Brain.hpp"
# include <string>

class Animal {

public:
	Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();

	virtual void	makeSound();
	virtual Brain	*getBrain() const;

protected:
	std::string type;

};

#endif
