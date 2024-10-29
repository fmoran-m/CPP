#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::~BitcoinExchange(void) {}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	this->dataBase = rhs.dataBase;
	return (*this);
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
	return;
}

void	BitcoinExchange::loadDatabase(void){
	std::ifstream	file;
	std::string		temp;

	file.open("data.csv");
	std::getline(file, temp); //Call to pass first line
	while (std::getline(file, temp))
		storeData(temp);
	return;
}

void	BitcoinExchange::parseInput(std::string const argvStr)
{
	std::string newStr;
	std::remove_copy(argvStr.begin(), argvStr.end(), newStr,  ' ');

	std::string::iterator pipe = find(newStr.begin(), newStr.end(), '|');

	if (pipe == newStr.end())
		throw std::invalid_argument("Error: format does not match");
	if (*(pipe - 1) == '-' || *newStr.begin() == '-')
		throw std::invalid_argument("Error: format does not match");
	int nPipes = std::count(newStr.begin(), pipe, '-');

	std::string::iterator it = newStr.begin();
	while(it != pipe)
	{
		if (*it != '-' && !isdigit(*it))
			throw std::invalid_argument("Error: format does not match");
		it++;
	}
	return;
}
// PRIVATE METHODS

void BitcoinExchange::storeData(std::string line){
	std::string::iterator it;
	float value;

	it = std::find(line.begin(), line.end(), ',');

	std::string key(line.begin(), it);
	std::string valueStr(it + 1, line.end());
	std::istringstream(valueStr) >> value;
	dataBase.insert(std::pair<std::string, float>(key, value));
	return;
}