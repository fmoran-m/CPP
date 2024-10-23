#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	try{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		Span sp(10000);

		sp.fillSpan();
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
