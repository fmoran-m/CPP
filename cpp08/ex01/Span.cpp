#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(void) : limit(0){
	std::cout << "Empty Span class" << std::endl;
	return;
}

Span::Span(unsigned int n) : limit(n){
	return;
}

Span::Span(Span const &src) {
	*this = src;
	return;
}
Span::~Span(void) {
	return;
}
Span &Span::operator=(Span const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}

void Span::addNumber(unsigned int n){
	if (container.size() >= this->limit)
		throw std::out_of_range("Error: full container");
	container.push_back(n);
	return;
}

unsigned int Span::longestSpan(void) const{
	if (container.empty() || container.size() == 1)
		throw std::logic_error("Error: not enough elements");

	 std::vector<unsigned int>::const_iterator max = std::max_element(container.begin(), container.end());
	 std::vector<unsigned int>::const_iterator min = std::min_element(container.begin(), container.end());

	 return (*max - *min);
}

unsigned int Span::shortestSpan(void){
	std::vector<unsigned int> tmp = container;
	unsigned int shortSpan = this->longestSpan();

	unsigned int value;

	if (container.empty() || container.size() == 1)
		throw std::logic_error("Error: not enough elements");
	sort(tmp.begin(), tmp.end());

	std::vector<unsigned int>::iterator it = tmp.begin();
	std::vector<unsigned int>::iterator next;
	for (; it < tmp.end() - 1; it++){
		next = it + 1;
		value = *next - *it;
		if (value < shortSpan)
			shortSpan = value;
	}
	return (shortSpan);
}

void	Span::fillSpan(void){
	srand(time(NULL));
	container.resize(limit);
	std::generate(container.begin(), container.end(), std::rand);
	return;
}

void	Span::printContainer(void){
	std::vector<unsigned int>::iterator it = container.begin();

	if (container.empty())
		throw std::logic_error("Error: empty container");
	for (; it < container.end(); it++){
		std::cout << *it << std::endl;
	}
	return;
}

unsigned int Span::spanSize(void) const{
	return (container.size());
}
