#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain {

public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &rhs);
	virtual ~Brain();

private:
	std::string ideas[100];
};

#endif
