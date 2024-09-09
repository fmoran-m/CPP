#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "Animal.hpp"

class Dog : public Animal{

public:
	Dog();
	Dog(const Dog &src);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound();

	std::string getType(void) const;

protected:
	std::string type;
};

#endif
