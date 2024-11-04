#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: incorrect number of arguments" << std::endl;
		return 1;
	}

	RPN rpn;
	std::string argvStr(argv[1]);

	rpn.calculateExpression(argvStr);

	return 0;
}