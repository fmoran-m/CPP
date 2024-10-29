#include "BitcoinExchange.hpp"
#include <map>
#include <iostream>
#include <ctime>

int main(void)
{
	std::cout << "date,exchange_rate" << std::endl;
	BitcoinExchange a;

	a.loadDatabase();
	std::map<std::string, float>::iterator it = a.dataBase.begin();
	for (; it != a.dataBase.end(); it++){
		std::cout << it->first <<','<< it->second << std::endl;
	}
	return 0;
}