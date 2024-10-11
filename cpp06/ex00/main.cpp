#include <string>
#include <sstream>
#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	std::string str;

	if (argc != 2)
	{
		std::cerr << "Error: incorrect number of arguments" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
