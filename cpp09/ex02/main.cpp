#include "PmergeMe.hpp"
#include <iostream>
#include <climits>
#include <string>
#include <iomanip>

bool isSortedVector(const std::vector<unsigned int> &vec)
{
    for (unsigned int i = 1; i < vec.size(); i++)
    {
        if (vec[i - 1] > vec[i])
            return false;
    }
    return true;
}

bool isSortedDeque(const std::deque<unsigned int> &deq)
{
    for (unsigned int i = 1; i < deq.size(); i++)
    {
        if (deq[i - 1] > deq[i])
            return false;
    }
    return true;
}

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
		return 1;
	}
	std::cout << "Before: ";
	for (unsigned int i = 0; i < a.getNumbersVector().size(); i++)
		std::cout << a.getNumbersVector()[i] << " ";
	std::cout << std::endl;

	float timeBeforeVector = a.getTime();
	a.applyVectorAlgorithm();
	float timeAfterVector = a.getTime();

	std::cout << "After (Vector): ";
	for (unsigned int i = 0; i < a.getNumbersVector().size(); i++)
		std::cout << a.getNumbersVector()[i] << " ";
	std::cout << std::endl;

	float timeBeforeDeque = a.getTime();
	a.applyDequeAlgorithm();
	float timeAfterDeque = a.getTime();
	std::cout << "After (Deque): ";
	for (unsigned int i = 0; i < a.getNumbersDeque().size(); i++)
		std::cout << a.getNumbersDeque()[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << a.getNumbersVector().size() << " elements with std::vector : " << std::fixed << std::setprecision(2) << ((timeAfterVector - timeBeforeVector) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;
	std::cout << "Time to process a range of " << a.getNumbersDeque().size() << " elements with std::deque : " << std::fixed << std::setprecision(2) << ((timeAfterDeque - timeBeforeDeque) / CLOCKS_PER_SEC) * 1000 << " ms" << std::endl;

	 // Verificar si los contenedores están ordenados
    if (isSortedVector(a.getNumbersVector()))
        std::cout << "The vector is sorted." << std::endl;
    else
	{
        std::cout << "The vector is NOT sorted." << std::endl;
	}

    if (isSortedDeque(a.getNumbersDeque()))
        std::cout << "The deque is sorted." << std::endl;
    else
	{
        std::cout << "The deque is NOT sorted." << std::endl;
	}

	return (0);
}
