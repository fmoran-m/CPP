#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <string>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return (1);
	}

	std::string argvStr;
	for (unsigned int i = 1; (int)i < argc; i++)
	{
		if (i > INT_MAX)
		{
			std::cerr << "Error: Argument overflow" << std::endl;
			return (1);
		}
		argvStr += argv[i];
		argvStr += ' ';
	}

	PmergeMe a;
	try{
		a.parseInput(argvStr);
	}catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "Vector: ";
	for (unsigned int i = 0; i < a.numbersVector.size(); i++)
		std::cout << a.numbersVector[i] << " ";
	std::cout << std::endl;

	std::cout << "Deque: ";
	for (unsigned int i = 0; i < a.numbersDeque.size(); i++)
		std::cout << a.numbersDeque[i] << " ";
	std::cout << std::endl;

	a.applyVectorAlgorithm();
	std::cout << "Vector: ";
	for (unsigned int i = 0; i < a.numbersVector.size(); i++)
		std::cout << a.numbersVector[i] << " ";
	std::cout << std::endl;

	a.applyDequeAlgorithm();
	std::cout << "Deque: ";
	for (unsigned int i = 0; i < a.numbersDeque.size(); i++)
		std::cout << a.numbersDeque[i] << " ";
	std::cout << std::endl;
	return 0;
}
