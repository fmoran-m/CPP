#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}
PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
	return;
}
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}

void	PmergeMe::parseInput(std::string &argvStr)
{
	std::stringstream	split(argvStr);
	std::string			token;
	int					temp;

	while(split >> token)
	{
		if (token.size() != 1 || !isdigit(*token.begin()))
			throw std::logic_error("Incorrect argument format");
		std::istringstream(token) >> temp;
		numbersVector.push_back(temp);
	}
	return;
}