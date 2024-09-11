#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain {

public:
	Brain();
	Brain(const Brain &src);
	Brain &operator=(const Brain &rhs);
	~Brain();

	std::string	getIdea(int index) const;
	void		setIdea(int index, std::string newIdea);
private:
	std::string ideas[100];
};

#endif
