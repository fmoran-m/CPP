#ifndef DOG_HPP
# define DOG_HPP
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog &src);
	Dog &operator=(const Dog &rhs);
	~Dog();

	void makeSound();

	Brain *getBrain() const;
protected:
	std::string type;
private:
	Brain *brain;
};

#endif
