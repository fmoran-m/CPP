#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include "Brain.hpp"
# include <string>

class AAnimal {

public:
	AAnimal();
	AAnimal(const AAnimal &src);
	AAnimal &operator=(const AAnimal &rhs);
	virtual ~AAnimal();

	virtual void	makeSound() = 0;
	virtual Brain	*getBrain() const;

protected:
	std::string type;

};

#endif
