#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <string>
#include <sys/time.h>

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

	std::cout << "Before: ";
	for (unsigned int i = 0; i < a.numbersVector.size(); i++)
		std::cout << a.numbersVector[i] << " ";
	std::cout << std::endl;

	struct timeval beforeVectorTime;
	struct timeval afterVectorTime;
	gettimeofday(&beforeVectorTime, NULL);
	a.applyVectorAlgorithm();
	gettimeofday(&afterVectorTime, NULL);

	std::cout << "After (Vector): ";
	for (unsigned int i = 0; i < a.numbersVector.size(); i++)
		std::cout << a.numbersVector[i] << " ";
	std::cout << std::endl;

	struct timeval beforeDequeTime;
	struct timeval afterDequeTime;
	gettimeofday(&beforeDequeTime, NULL);
	a.applyDequeAlgorithm();
	gettimeofday(&afterDequeTime, NULL);

	std::cout << "After (Deque): ";
	for (unsigned int i = 0; i < a.numbersDeque.size(); i++)
		std::cout << a.numbersDeque[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << a.numbersVector.size() << " elements with std::vector : " << afterVectorTime.tv_sec - beforeVectorTime.tv_usec << std::endl;
	std::cout << "Time to process a range of " << a.numbersDeque.size() << " elements with std::deque : " << afterDequeTime.tv_sec - beforeDequeTime.tv_usec << std::endl;
	return 0;
}
