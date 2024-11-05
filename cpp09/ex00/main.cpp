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
	BitcoinExchange a;
	a.loadDatabase();
	a.loadInput(argv[1]);

	return 0;
}