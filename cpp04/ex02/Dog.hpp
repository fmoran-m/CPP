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

	void makeSound();

	Brain *getBrain() const;
protected:
	std::string type;
private:
	Brain *brain;
};

#endif
