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

	bool			lastElementExists = false;

	if (numbersVector.size() % 2 != 0)
		lastElementExists = true;

	std::vector<std::pair<unsigned int, unsigned int> > pairVector = this->pairNumbers(lastElementExists);
	this->sortPairs(pairVector);
	this->sortLargerNumbers(pairVector);
	return;
}

//PRIVATE METHODS

std::vector<std::pair<unsigned int, unsigned int> > PmergeMe::pairNumbers(bool lastElementExists){
	std::vector<std::pair<unsigned int, unsigned int> > pairVector;
	std::vector<unsigned int>::iterator it = numbersVector.begin();

	if (lastElementExists == false){
		while(it != numbersVector.end()){
			pairVector.push_back(std::pair<unsigned int, unsigned int>(*it, *(it + 1)));
			it += 2;
		}
	}
	else{
		while(it != numbersVector.end() - 1){
			pairVector.push_back(std::pair<unsigned int, unsigned int>(*it, *(it + 1)));
			it += 2;
		}
	}
	return (pairVector);
}

void PmergeMe::sortPairs(std::vector<std::pair<unsigned int, unsigned int> > &pairVector)
{
	unsigned int temp = 0;

	std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairVector.begin();
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
}

void PmergeMe::sortLargerNumbers(std::vector<std::pair<unsigned int, unsigned int> > &pairVector)
{
	size_t size = pairVector.size();
	mergeSort(pairVector, 0, size - 1);
	return;
}

void PmergeMe::mergeSort(std::vector<std::pair<unsigned int, unsigned int> > &pairVector, size_t begin, size_t end)
{
	if (end == begin)
		return;

	size_t mid = begin + (end - begin) / 2;

	mergeSort(pairVector, begin, mid);
	mergeSort(pairVector, mid + 1, end);
	this->merge(pairVector, begin, mid, end);
}

void PmergeMe::merge(std::vector<std::pair<unsigned int, unsigned int> > &pairVector, size_t begin, size_t mid, size_t end)
{
	std::vector<std::pair<unsigned int, unsigned int> > leftVector(pairVector.begin() + begin, pairVector.begin() + mid + 1);
	std::vector<std::pair<unsigned int, unsigned int> > rightVector(pairVector.begin() + mid + 1, pairVector.begin() + end + 1); //A lo mejor hace falta sumar 1

	size_t lSize = mid - begin + 1;
	size_t rSize = end - mid;

	size_t l = 0;
	size_t r = 0;
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairVector.begin() + begin; 

	while (l < lSize && r < rSize)
	{
		if (leftVector[l].first <= rightVector[r].first)
		{
			*it = leftVector[l];
			l++;
		}
		else
		{
			*it = rightVector[r];
			r++;
		}
		it++;
	}
	while (l < lSize){
		*it = leftVector[l];
		l++;
		it++;
	}
	while (r < rSize){
		*it = rightVector[r];
		r++;
		it++;
	}
	return;
}

std::vector<unsigned int> PmergeMe::sortVector(std::vector<std::pair<unsigned int, unsigned int> > &pairVector)
{
	std::vector<unsigned int> sortedVector;
	std::vector<unsigned int> pend;

// Main Array and pend vector creation

	std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairVector.begin();
	while (it != pairVector.end()){
		sortedVector.push_back(it->first);
		pend.push_back(it->second);
		it++;
	}

// Insert first element of pend at the beginning of the main vector: we know it is smaller that the first element

	sortedVector.insert(sortedVector.begin(), pend[0]);
}