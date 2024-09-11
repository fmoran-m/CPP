#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>

class WrongAnimal {

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &src);
	WrongAnimal &operator=(const WrongAnimal &rhs);
	virtual ~WrongAnimal();

	void makeSound();

	std::string getType(void) const;

protected:
	std::string type;
};

#endif
