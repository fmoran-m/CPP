#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat();
	WrongCat(const WrongCat &src);
	WrongCat &operator=(const WrongCat &rhs);
	~WrongCat();

	void makeSound();

	std::string getType(void) const;

protected:
	std::string type;
};

#endif
