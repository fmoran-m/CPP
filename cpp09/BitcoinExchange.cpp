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

void	BitcoinExchange::loadInput(char *argvStr)
{
	std::ifstream	file;
	std::string		temp;

	file.open(argvStr);
	//std::getline(file, temp); //Call to pass first line
	while (std::getline(file, temp))
	{
		try{
			this->printLineConversion(temp);
		}catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return;
}

// PRIVATE METHODS
void	BitcoinExchange::printLineConversion(std::string const line)
{
	std::string newStr;
	std::remove_copy(line.begin(), line.end(), newStr.begin(),  ' ');

	std::string::iterator pipe = find(newStr.begin(), newStr.end(), '|');
	try{
		this->parseDate(pipe ,newStr);
	}catch(std::exception &e){
		throw e;
	}

	try{
		this->parseRatio(newStr);
	}catch(std::exception &e){
		throw e;
	}
	dateValueToMap(newStr, pipe);
	return;
}

void	BitcoinExchange::parseDate(std::string::iterator pipe, std::string newStr) const
{
	if (pipe == newStr.end())
		throw std::invalid_argument(FORMAT_ERROR);

	if (*(pipe - 1) == '-' || *newStr.begin() == '-')
		throw std::invalid_argument(FORMAT_ERROR);

	int nSlash = std::count(newStr.begin(), pipe, '-');
	if (nSlash != 2)
		throw std::invalid_argument(FORMAT_ERROR); //Aquí está entrando todo el rato, no debería

	std::string::iterator it = newStr.begin();
	while(it != pipe)
	{
		if (*it != '-' && !isdigit(*it))
			throw std::invalid_argument(FORMAT_ERROR);
		it++;
	}
	return;
}

void	BitcoinExchange::parseRatio(std::string newStr) const
{
	bool point = false;

	std::string::iterator it = newStr.begin();
	if ((it + 1) != newStr.end() && *(it + 1) == '-')
		it++;
	while (it != newStr.end())
	{
		if (!isdigit(*it))
			throw std::invalid_argument(FORMAT_ERROR);
		if (*it == '.' && point == true)
			throw std::invalid_argument(FORMAT_ERROR);
		if (*it == '.')
			point = true;
		it++;
	}
	return;
}

void	BitcoinExchange::storeData(std::string line){
	std::string::iterator it;
	float value;

	it = std::find(line.begin(), line.end(), ',');

	std::string key(line.begin(), it);
	std::string valueStr(it + 1, line.end());
	std::istringstream(valueStr) >> value;
	dataBase.insert(std::pair<std::string, float>(key, value));
	return;
}

void	BitcoinExchange::dateValueToMap(std::string newStr, std::string::iterator pipe)
{
	std::string date(newStr.begin(), pipe);
	std::string ratio(pipe + 1, newStr.end());
	float ratioFloat;
	std::istringstream(ratio) >> ratioFloat;
	inputData.insert(std::pair<std::string, float>(date, ratioFloat));
	std::cout << date << " | " << ratio << std::endl;
	return;
}