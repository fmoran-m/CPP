#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "Animal.hpp"

class Cat : public Animal {

public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);
	~Cat();

	virtual void makeSound();

protected:
	std::string type;

};

#endif
