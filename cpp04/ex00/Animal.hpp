#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal {

public:
	Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &rhs);
	virtual ~Animal();

	virtual void makeSound();

	virtual std::string getType(void) const;

protected:
	std::string type;
};

#endif
