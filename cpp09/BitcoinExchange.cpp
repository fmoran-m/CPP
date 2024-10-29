#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

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