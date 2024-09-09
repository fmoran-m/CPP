#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "Animal.hpp"

class Cat : public Animal {

public:
	Cat();
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);
	~Cat();

	void makeSound();

	std::string getType(void) const;

protected:
	std::string type;
};

#endif
