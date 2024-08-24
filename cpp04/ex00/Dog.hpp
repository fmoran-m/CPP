#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "Animal.hpp"

class Dog : public Animal{

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &src);
	Dog &operator=(const Dog &rhs);
	~Dog();

	virtual void makeSound();

protected:
	std::string type;

};

#endif
