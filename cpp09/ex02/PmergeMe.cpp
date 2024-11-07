#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>

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
	unsigned long long int		temp;

	while(split >> token)
	{
		for (std::string::iterator it = token.begin(); it != token.end(); it++)
		{
			if (!isdigit(*it))
				throw std::logic_error("Incorrect argument format");
		}
		std::istringstream(token) >> temp;
		if (temp > UINT_MAX)
			throw std::overflow_error("Number overflow");
		numbersVector.push_back(temp);
	}
	return;
}

void	PmergeMe::applyAlgorithm(void){
	unsigned int	lastElement;
	bool			lastElementExists = false;

	if (numbersVector.size() % 2 != 0)
	{
		lastElement = *(numbersVector.end() - 1);
		lastElementExists = true;
	}

	std::vector<std::pair<unsigned int, unsigned int>> pairVector = this->pairNumbers(lastElementExists);
	pairVector = sortPairs(pairVector);
	pairVector = sortLargerNumbers(pairVector);

	return;
}

//PRIVATE METHODS

std::vector<std::pair<unsigned int, unsigned int>> PmergeMe::pairNumbers(bool lastElementExists){

	std::vector<std::pair<unsigned int, unsigned int>> pairVector;
	std::vector<unsigned int>::iterator it = numbersVector.begin();
	std::vector<std::pair<unsigned int, unsigned int>>::iterator itPair = pairVector.begin();
	int i = 1;
	while (it != numbersVector.end() - lastElementExists)
	{
		if (i == 3)
		{
			i = 1;
			++itPair;
		}
		if (i == 1)
		{
			itPair->first = *it;
			it++;
		}
		else
		{
			itPair->second = *it;
			it++;
		}
	}
	return (pairVector);
}

std::vector<std::pair<unsigned int, unsigned int>> PmergeMe::sortPairs(std::vector<std::pair<unsigned int, unsigned int>> pairVector)
{
	unsigned int temp = 0;

	std::vector<std::pair<unsigned int, unsigned int>>::iterator it = pairVector.begin();
	while (it != pairVector.end())
	{
		if (it->second > it->first)
		{
			temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
		it++;
	}
	return (pairVector);
}

std::vector<std::pair<unsigned int, unsigned int>> PmergeMe::sortLargerNumbers(std::vector<std::pair<unsigned int, unsigned int>> pairVector)
{
return ()
}
