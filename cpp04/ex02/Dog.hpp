#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal{

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &src);
	Dog &operator=(const Dog &rhs);
	~Dog();

	virtual void makeSound();

protected:
	std::string type;
	Brain *brain;
};

#endif
