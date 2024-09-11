#ifndef CAT_HPP
# define CAT_HPP
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

public:
	Cat();
	Cat(std::string type);
	Cat(const Cat &src);
	Cat &operator=(const Cat &rhs);
	~Cat();

	void makeSound();

	Brain *getBrain() const;

protected:
	std::string type;
private:
	Brain *brain;
};

#endif
