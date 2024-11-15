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
	a.applyVectorAlgorithm();
	return 0;
}
