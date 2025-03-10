/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:57 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:51:05 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
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
	{
		std::vector<unsigned int>::iterator itInsert = std::lower_bound(numbersVector.begin(), numbersVector.end(), lastElement);
		numbersVector.insert(itInsert, lastElement);
	}
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
	{
		std::deque<unsigned int>::iterator itInsert = std::lower_bound(numbersDeque.begin(), numbersDeque.end(), lastElement);
		numbersDeque.insert(itInsert, lastElement);
	}
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

	std::vector<unsigned int>::iterator jacobIt = jacobsthalSequence.begin();
	while(jacobIt != jacobsthalSequence.end())
	{
		jacobInsertion(jacobIt, pend, sortedVector);
		jacobIt++;
	}
	if (jacobsthalSequence.empty())
	{
		unsigned int num = *(pend.begin() + 1);
		std::vector<unsigned int>::iterator insertIt = std::lower_bound(sortedVector.begin(), sortedVector.end() ,num);
		sortedVector.insert(insertIt, num);
	}
	else if (!pend.empty() && pend.size() > jacobsthalSequence.back())
	{
		unsigned int lastIndex = pend.size() - 1;
		std::vector<unsigned int>::iterator itBack = sortedVector.end();
		while (lastIndex != jacobsthalSequence.back() - 1)
		{
			std::vector<unsigned int>::iterator insertIt = std::lower_bound(sortedVector.begin(), itBack, pend[lastIndex]);
			sortedVector.insert(insertIt, pend[lastIndex]);
			lastIndex--;
			itBack = sortedVector.end();
		}
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
	unsigned int pendIndex = *jacobIt;
	unsigned int sortIndex = (*jacobIt * 2) - 2; //Puede que sea -2??
	if (pendIndex == 3){
		while (pendIndex > 1)
		{
			std::vector<unsigned int>::iterator itInsert = std::lower_bound(sortedVector.begin(), sortedVector.begin() + sortIndex, pend[pendIndex - 1]);
			sortedVector.insert(itInsert, pend[pendIndex - 1]);
			pendIndex--;
		}
	}
	else{
		while(pendIndex > *(jacobIt - 1))
		{
			std::vector<unsigned int>::iterator itInsert = std::lower_bound(sortedVector.begin(), sortedVector.begin() + sortIndex, pend[pendIndex - 1]);
			sortedVector.insert(itInsert, pend[pendIndex - 1]);
			pendIndex--;
		}
	}
}

//PRIVATE METHODS DEQUE

std::deque<std::pair<unsigned int, unsigned int> > PmergeMe::pairNumbersDeque(bool lastElementExists){
	std::deque<std::pair<unsigned int, unsigned int> > pairDeque;
	std::deque<unsigned int>::iterator it = numbersDeque.begin();

	if (lastElementExists == false){
		while(it != numbersDeque.end()){
			std::deque<unsigned int>::iterator advancedIt = it;
			std::advance(advancedIt, 1);
			pairDeque.push_back(std::pair<unsigned int, unsigned int>(*it, *advancedIt));
			std::advance(it, 2);
		}
	}
	else{
		while(it != numbersDeque.end() - 1){
			std::deque<unsigned int>::iterator advancedIt = it;
			std::advance(advancedIt, 1);
			pairDeque.push_back(std::pair<unsigned int, unsigned int>(*it, *advancedIt));
			std::advance(it, 2);
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
		std::advance(it, 1);
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
	std::deque<std::pair<unsigned int, unsigned int> >::iterator itBegin = pairDeque.begin();
	std::deque<std::pair<unsigned int, unsigned int> >::iterator itMid = pairDeque.begin();
	std::deque<std::pair<unsigned int, unsigned int> >::iterator itEnd = pairDeque.begin();

	std::advance(itBegin, begin);
	std::advance(itMid, mid + 1);
	std::advance(itEnd, end + 1);

	std::deque<std::pair<unsigned int, unsigned int> > leftVector(itBegin, itMid);
	std::deque<std::pair<unsigned int, unsigned int> > rightVector(itMid, itEnd);

	size_t lSize = mid - begin + 1;
	size_t rSize = end - mid;

	size_t l = 0;
	size_t r = 0;
	std::deque<std::pair<unsigned int, unsigned int> >::iterator it = itBegin;

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
		std::advance(it, 1);
	}

	sortedDeque.insert(sortedDeque.begin(), pendDeque[0]);
	if (pairDeque.size() == 1)
		return (sortedDeque);

	std::deque<unsigned int> jacobsthalSequence = this->generateJacobsthalDeque(pendDeque.size());

	std::deque<unsigned int>::iterator jacobIt = jacobsthalSequence.begin();
	while(jacobIt != jacobsthalSequence.end())
	{
		jacobInsertionDeque(jacobIt, pendDeque, sortedDeque);
		std::advance(jacobIt, 1);
	}
	if (jacobsthalSequence.empty())
	{
		std::deque<unsigned int>::iterator itBegin = pendDeque.begin();
		std::advance(itBegin, 1);
		unsigned int num = *itBegin;
		std::deque<unsigned int>::iterator insertIt = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), num);
		sortedDeque.insert(insertIt, num);
	}
	else if (!pendDeque.empty() && pendDeque.size() > jacobsthalSequence.back())
	{
		unsigned int lastIndex = pendDeque.size() - 1;
		std::deque<unsigned int>::iterator itBack = sortedDeque.end();
		while (lastIndex != jacobsthalSequence.back() - 1)
		{
			std::deque<unsigned int>::iterator insertIt = std::lower_bound(sortedDeque.begin(), itBack, pendDeque[lastIndex]);
			sortedDeque.insert(insertIt, pendDeque[lastIndex]);
			lastIndex--;
			itBack = sortedDeque.end();
		}
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
	unsigned int pendIndex = *jacobIt;
	unsigned int sortIndex = (*jacobIt * 2) - 2;
	if (pendIndex == 3){
		while (pendIndex > 1)
		{
			std::deque<unsigned int>::iterator itEnd = sortedDeque.begin();
			if (sortIndex < sortedDeque.size())
				std::advance(itEnd, sortIndex);
			else
				itEnd = sortedDeque.end();
			std::deque<unsigned int>::iterator itInsert = std::lower_bound(sortedDeque.begin(), itEnd, pendDeque[pendIndex - 1]);
			sortedDeque.insert(itInsert, pendDeque[pendIndex - 1]);
			pendIndex--;
		}
	}
	else{
		while(pendIndex > *(jacobIt - 1))
		{
			std::deque<unsigned int>::iterator itEnd = sortedDeque.begin();
			if (sortIndex < sortedDeque.size())
				std::advance(itEnd, sortIndex);
			else
				itEnd = sortedDeque.end();
			std::deque<unsigned int>::iterator itInsert = std::lower_bound(sortedDeque.begin(), itEnd, pendDeque[pendIndex - 1]);
			sortedDeque.insert(itInsert, pendDeque[pendIndex - 1]);
			pendIndex--;
		}
	}
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
