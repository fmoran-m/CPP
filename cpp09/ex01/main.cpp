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
	if (argvStr.empty())
	{
		std::cerr << "Error: Incorrect argument format" << std::endl;
		return 1;
	}
	std::string::iterator it = argvStr.begin();
	while(it != argvStr.end())
	{
		if (!std::isspace(*it))
			break;
		it++;
	}
	if (it == argvStr.end())
	{
		std::cerr << "Error: Incorrect argument format" << std::endl;
		return 1; 
	}
	rpn.calculateExpression(argvStr);

	return 0;
}