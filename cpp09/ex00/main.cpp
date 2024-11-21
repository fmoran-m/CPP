#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Incorrect number of arguments" << std::endl;
		return 1;
	}
	std::string argvStr = argv[1];
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
	BitcoinExchange a;
	try{
		a.loadDatabase();
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}
	a.loadInput(argv[1]);

	return 0;
}