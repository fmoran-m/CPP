#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cmath>

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
	unsigned long int	temp;

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
		numbersDeque.push_back(temp);
	}
	if (numbersVector.empty() || numbersDeque.empty())
		throw std::logic_error("No elements found");
	return;
}

void	PmergeMe::applyVectorAlgorithm(void){

	bool			lastElementExists = false;
	unsigned int	lastElement = 0;

	if (numbersVector.size() <= 1)
		return;
	if (numbersVector.size() % 2 != 0)
	{
		lastElementExists = true;
		lastElement = *(numbersVector.end() - 1);
	}
	std::vector<std::pair<unsigned int, unsigned int> > pairVector = this->pairNumbers(lastElementExists);
	this->sortPairs(pairVector);
	this->sortLargerNumbers(pairVector);
	numbersVector = sortVector(pairVector);
	if (lastElementExists == true)
		binarySearch(lastElement, numbersVector, 0, numbersVector.size() - 1);
	return;
}

void	PmergeMe::applyDequeAlgorithm(void){

	bool			lastElementExists = false;
	unsigned int	lastElement = 0;

	if (numbersDeque.size() <= 1)
		return;
	if (numbersDeque.size() % 2 != 0)
	{
		lastElementExists = true;
		lastElement = *(numbersDeque.end() - 1);
	}
	std::deque<std::pair<unsigned int, unsigned int> > pairDeque = this->pairNumbersDeque(lastElementExists);
	this->sortPairsDeque(pairDeque);
	this->sortLargerNumbersDeque(pairDeque);
	numbersDeque = sortDeque(pairDeque);
	if (lastElementExists == true)
		binarySearchDeque(lastElement, numbersDeque, 0, numbersDeque.size() - 1);
	return;
}

//PRIVATE METHODS VECTOR

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
	std::vector<std::pair<unsigned int, unsigned int> > rightVector(pairVector.begin() + mid + 1, pairVector.begin() + end + 1);

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

	std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairVector.begin();
	while (it != pairVector.end()){
		sortedVector.push_back(it->first);
		pend.push_back(it->second);
		it++;
	}

	sortedVector.insert(sortedVector.begin(), pend[0]);
	if (pairVector.size() == 1)
		return (sortedVector);

	std::vector<unsigned int> jacobsthalSequence = this->generateJacobsthal(pend.size());
	unsigned int last;
	unsigned int sortedIndex;

	std::vector<unsigned int>::iterator jacobIt = jacobsthalSequence.begin();
	while(jacobIt != jacobsthalSequence.end())
	{
		jacobInsertion(jacobIt, pend, sortedVector);
		jacobIt++;
	}
	if (!jacobsthalSequence.empty()){
		last = *(jacobsthalSequence.end() - 1);
		sortedIndex = (last * 2) - 1;
	}
	else{
		last = 1;
		sortedIndex = 1;
	}
	std::vector<unsigned int>::iterator pendIt = pend.begin() + last;
	while(pendIt != pend.end())
	{ 
		binarySearch(*pendIt, sortedVector, 0, sortedIndex);
		pendIt++;
		sortedIndex++;
	}
	return (sortedVector);
}

std::vector<unsigned int> PmergeMe::generateJacobsthal(size_t size)
{
	unsigned int value = 3;
	std::vector<unsigned int> jacobsthalSequence;
	while (value <= size)
	{
		jacobsthalSequence.push_back(value);
		if (jacobsthalSequence.size() == 1){
			value += 2;
		}
		else
			value = *(jacobsthalSequence.end() - 1) + (*(jacobsthalSequence.end() - 2) * 2);
	}
	return (jacobsthalSequence);
}

void PmergeMe::jacobInsertion(std::vector<unsigned int>::iterator jacobIt, std::vector<unsigned int> &pend, std::vector<unsigned int> &sortedVector)
{
	unsigned int pendIndex = *jacobIt - 1;
	unsigned int sortIndex = (*jacobIt * 2) - 2;
	if (pendIndex == 2){
		while (pendIndex > 0)
		{
			binarySearch(pend[pendIndex], sortedVector, 0, sortIndex);
			pendIndex--;
		}
	}
	else{
		while(pendIndex + 1 > *(jacobIt - 1))
		{
			binarySearch(pend[pendIndex], sortedVector, 0, sortIndex);
			pendIndex--;
		}
	}
}

unsigned int PmergeMe::binarySearch(unsigned int n, std::vector<unsigned int> &sortedVector, unsigned int begin, unsigned int end)
{
    if (begin >= end) {
		if (n < sortedVector[begin])
        	sortedVector.insert(sortedVector.begin() + begin, n);
		else
        	sortedVector.insert(sortedVector.begin() + begin + 1, n);
        return n;
    }

    unsigned int mid = (begin + (end - begin) / 2);
	std::cout << "n: " << n << " mid: " << mid << std::endl;
    if (sortedVector[mid] == n) {
        sortedVector.insert(sortedVector.begin() + mid, n);
        return n;
    }

    if (n < sortedVector[mid]) 
        return binarySearch(n, sortedVector, begin, mid);
    else 
        return binarySearch(n, sortedVector, mid + 1, end);
}

//PRIVATE METHODS DEQUE

std::deque<std::pair<unsigned int, unsigned int> > PmergeMe::pairNumbersDeque(bool lastElementExists){
	std::deque<std::pair<unsigned int, unsigned int> > pairDeque;
	std::deque<unsigned int>::iterator it = numbersDeque.begin();

	if (lastElementExists == false){
		while(it != numbersDeque.end()){
			pairDeque.push_back(std::pair<unsigned int, unsigned int>(*it, *(it + 1)));
			it += 2;
		}
	}
	else{
		while(it != numbersDeque.end() - 1){
			pairDeque.push_back(std::pair<unsigned int, unsigned int>(*it, *(it + 1)));
			it += 2;
		}
	}
	return (pairDeque);
}

void PmergeMe::sortPairsDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque)
{
	unsigned int temp = 0;

	std::deque<std::pair<unsigned int, unsigned int> >::iterator it = pairDeque.begin();
	while (it != pairDeque.end())
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

void PmergeMe::sortLargerNumbersDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque)
{
	size_t size = pairDeque.size();
	mergeSortDeque(pairDeque, 0, size - 1);
	return;
}

void PmergeMe::mergeSortDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque, size_t begin, size_t end)
{
	if (end == begin)
		return;

	size_t mid = begin + (end - begin) / 2;

	mergeSortDeque(pairDeque, begin, mid);
	mergeSortDeque(pairDeque, mid + 1, end);
	this->mergeDeque(pairDeque, begin, mid, end);
}

void PmergeMe::mergeDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque, size_t begin, size_t mid, size_t end)
{
	std::deque<std::pair<unsigned int, unsigned int> > leftVector(pairDeque.begin() + begin, pairDeque.begin() + mid + 1);
	std::deque<std::pair<unsigned int, unsigned int> > rightVector(pairDeque.begin() + mid + 1, pairDeque.begin() + end + 1);

	size_t lSize = mid - begin + 1;
	size_t rSize = end - mid;

	size_t l = 0;
	size_t r = 0;
	std::deque<std::pair<unsigned int, unsigned int> >::iterator it = pairDeque.begin() + begin; 

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

std::deque<unsigned int> PmergeMe::sortDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque)
{
	std::deque<unsigned int> sortedDeque;
	std::deque<unsigned int> pendDeque;

	std::deque<std::pair<unsigned int, unsigned int> >::iterator it = pairDeque.begin();
	while (it != pairDeque.end()){
		sortedDeque.push_back(it->first);
		pendDeque.push_back(it->second);
		it++;
	}

	sortedDeque.insert(sortedDeque.begin(), pendDeque[0]);
	if (pairDeque.size() == 1)
		return (sortedDeque);

	std::deque<unsigned int> jacobsthalSequence = this->generateJacobsthalDeque(pendDeque.size());
	unsigned int last;
	unsigned int sortedIndex;

	std::deque<unsigned int>::iterator jacobIt = jacobsthalSequence.begin();
	while(jacobIt != jacobsthalSequence.end())
	{
		jacobInsertionDeque(jacobIt, pendDeque, sortedDeque);
		jacobIt++;
	}
	if (!jacobsthalSequence.empty())
	{
		last = *(jacobsthalSequence.end() - 1);
		sortedIndex = (last * 2) - 1;
	}
	else{
		last = 1;
		sortedIndex = 1;
	}
	std::deque<unsigned int>::iterator pendIt = pendDeque.begin() + last;
	while(pendIt != pendDeque.end())
	{ 
		binarySearchDeque(*pendIt, sortedDeque, 0, sortedIndex);
		pendIt++;
		sortedIndex++;
	}
	return (sortedDeque);
}

std::deque<unsigned int> PmergeMe::generateJacobsthalDeque(size_t size)
{
	unsigned int value = 3;
	std::deque<unsigned int> jacobsthalSequence;
	while (value <= size)
	{
		jacobsthalSequence.push_back(value);
		if (jacobsthalSequence.size() == 1){
			value += 2;
		}
		else
			value = *(jacobsthalSequence.end() - 1) + (*(jacobsthalSequence.end() - 2) * 2);
	}
	return (jacobsthalSequence);
}

void PmergeMe::jacobInsertionDeque(std::deque<unsigned int>::iterator jacobIt, std::deque<unsigned int> &pendDeque, std::deque<unsigned int> &sortedDeque)
{
	unsigned int pendIndex = *jacobIt - 1;
	unsigned int sortIndex = (*jacobIt * 2) - 2;
	if (pendIndex == 2){
		while (pendIndex > 0)
		{
			binarySearchDeque(pendDeque[pendIndex], sortedDeque, 0, sortIndex);
			pendIndex--;
		}
	}
	else{
		while(pendIndex + 1 > *(jacobIt - 1))
		{
			binarySearchDeque(pendDeque[pendIndex], sortedDeque, 0, sortIndex);
			pendIndex--;
		}
	}
}

unsigned int PmergeMe::binarySearchDeque(unsigned int n, std::deque<unsigned int> &sortedDeque, unsigned int begin, unsigned int end)
{
    if (begin >= end) {
		if (n < sortedDeque[begin])
        	sortedDeque.insert(sortedDeque.begin() + begin, n);
		else
        	sortedDeque.insert(sortedDeque.begin() + begin + 1, n);
        return n;
    }

    unsigned int mid = begin + (end - begin) / 2;
    if (sortedDeque[mid] == n) {
        sortedDeque.insert(sortedDeque.begin() + mid, n);
        return n;
    }

    if (n < sortedDeque[mid]) 
        return binarySearchDeque(n, sortedDeque, begin, mid);
    else 
        return binarySearchDeque(n, sortedDeque, mid + 1, end);
}

float	PmergeMe::getTime(void)
{
	clock_t ts = clock();

	return (ts);
}

std::vector<unsigned int> PmergeMe::getNumbersVector(void)
{
	return (numbersVector);
}

std::deque<unsigned int> PmergeMe::getNumbersDeque(void)
{
	return (numbersDeque);
}
