#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>
#include <ctime>
#include <fstream>

int main(int argc, char **argv)
{
	std::string argvStr = argv[1];
	if (argc != 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return 1;
	}
	BitcoinExchange a;
	a.loadDatabase();
	a.parseInput(argvStr);

	return 0;
}