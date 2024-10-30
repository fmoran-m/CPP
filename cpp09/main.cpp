#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>
#include <ctime>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return 1;
	}
	char  *argvStr = argv[1];
	BitcoinExchange a;
	a.loadDatabase();
	a.loadInput(argvStr);

	return 0;
}