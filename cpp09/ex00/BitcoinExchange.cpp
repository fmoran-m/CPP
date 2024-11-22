/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:49:44 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:52:12 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <climits>

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
	if (!file.is_open())
		throw std::logic_error("Error: database does not exist");
	std::getline(file, temp); //Call to pass first line
	if (temp != "date,exchange_rate")
		throw std::logic_error("Error: corrupted database");
	try{
		while (std::getline(file, temp))
			storeData(temp);
	} catch(std::exception &e){
		throw;
	}
	return;
}

void	BitcoinExchange::loadInput(char *argvStr)
{
	std::ifstream	file;
	std::string		temp;

	file.open(argvStr);
	if (!file.is_open())
	{
		std::cerr << "Error: file does not exist" << std::endl;
		return;
	}
	std::getline(file, temp);
	if (temp != "date | value")
	{
		std::cerr << "Error: Input file does not include a header" << std::endl;
		return;
	}
	while (std::getline(file, temp))
	{
		try{
			this->lineConversion(temp);
		}catch(std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	return;
}

// PRIVATE METHODS
void	BitcoinExchange::lineConversion(std::string const line)
{
	std::string newStr = line;
	std::string::iterator pipe;
	try{
		pipe = newStr.begin() + this->findSeparator(line);
	}catch(std::exception &e){
		pipe = newStr.end();
	}
	try{
		this->parseDate(pipe ,newStr);
		pipe = newStr.begin() + this->findSeparator(line);
		this->parseRatio(pipe, newStr);
		printConversion(newStr, pipe);
	}catch(std::exception &e){
		throw;
	}
	return;
}

void	BitcoinExchange::parseDate(std::string::iterator &pipe, std::string &newStr)
{
	std::string dateStr(newStr.begin(), pipe);

	if (*(pipe - 1) == '-' || *newStr.begin() == '-')
		throw std::invalid_argument(BAD_INPUT + dateStr);

	int nSlash = std::count(newStr.begin(), pipe, '-');
	if (nSlash != 2)
		throw std::invalid_argument(BAD_INPUT + dateStr);
	
	if (newStr.find("--") != std::string::npos)
		throw std::invalid_argument(BAD_INPUT + dateStr);

	std::string::iterator it = newStr.begin();
	while(it != pipe)
	{
		if (*it != '-' && !isdigit(*it))
			throw std::invalid_argument(BAD_INPUT + dateStr);
		it++;
	}
	getRealDate(newStr);
	return;
}

void	BitcoinExchange::parseRatio(std::string::iterator &pipe, std::string &newStr) const
{
	bool point = false;
	bool negFlag = false;

	std::string::iterator it = pipe + 3;
	if (it == newStr.end())
		throw std::invalid_argument("Error: invalid ratio");
	if (*it == '-')
	{
		it++;
		negFlag = true;
	}
	while (it != newStr.end())
	{
		if (!isdigit(*it) && *it != '.')
			throw std::invalid_argument("Error: invalid ratio");
		if (*it == '.' && point == true)
			throw std::invalid_argument("Error: invalid ratio");
		if (*it == '.')
			point = true;
		it++;
	}
	std::string ratioStr(pipe + 3, newStr.end());

	long long int ratio;

	std::istringstream(ratioStr) >> ratio;
	if (ratio == 0 && negFlag == true)
		throw std::invalid_argument("Error: invalid ratio");
	if (ratio > 1000)
		throw std::invalid_argument("Error: too large a number");
	if (ratio > INT_MAX)
		throw std::invalid_argument("Error: too large a number");
	if (ratio < 0)
		throw std::invalid_argument("Error: not a positive number");
	return;
}

void	BitcoinExchange::storeData(std::string line){
	std::string::iterator it;
	float value;

	it = std::find(line.begin(), line.end(), ',');
	if (it == line.end())
		throw std::logic_error("Error: Corrupted database");
	
	try{
		std::string key(line.begin(), it);
		parseDateDatabase(key);
		std::string valueStr(it + 1, line.end());
		parseRatioDatabase(valueStr);
		std::istringstream(valueStr) >> value;
		dataBase[key] = value;
	} catch(std::exception &e){
		throw std::logic_error("Error: Corrupted database");
	}
	return;
}

void	BitcoinExchange::printConversion(std::string &newStr, std::string::iterator &pipe)
{
	std::string date(newStr.begin(), pipe);
	std::string ratio(pipe + 3, newStr.end());
	float ratioFloat;
	std::istringstream(ratio) >> ratioFloat;

	float conversion;
	std::map<std::string, float>::iterator it = this->dataBase.begin();

	while(it != this->dataBase.end())
	{
		if (date == it->first)
		{
			conversion = it->second * ratioFloat;
			std::cout << date << " => " << ratioFloat <<  " = " << conversion << std::endl;
			return;
		}
		else if (it->first > date && it != dataBase.begin())
		{
			it--;
			conversion = it->second * ratioFloat;
			std::cout << date << " => " << ratioFloat <<  " = " << conversion << std::endl;
			return;
		}
		else if (it->first > date && it == dataBase.begin())
		{
			conversion = dataBase.begin()->second * ratioFloat;
			std::cout << date << " => " << ratioFloat <<  " = " << conversion << std::endl;
			return;
		}
		it++;
	}
	return;
}

size_t BitcoinExchange::findSeparator(std::string const &line)
{
	std::string newStr;
	size_t		pipeFoundedPos;

	newStr = line;
	pipeFoundedPos = newStr.find(" | ");
	if (pipeFoundedPos == std::string::npos)
		throw std::invalid_argument("Error: Separator not found");
	return (pipeFoundedPos);
}

struct tm BitcoinExchange::getRealDate(std::string &newStr)
{
	try{
		std::string::iterator it = std::find(newStr.begin(), newStr.end(), ' ');

		std::string date(newStr.begin(), it);
		struct tm time;

		time.tm_year = getYear(date);
		time.tm_mon = getMonth(date);
		time.tm_mday = getDay(date, time.tm_year, time.tm_mon);
		return time;
	} catch (std::exception &e){
		throw;
	}
}

int	BitcoinExchange::getYear(std::string &date)
{
	std::string::iterator dash = std::find(date.begin(), date.end(), '-');
	std::string yearStr(date.begin(), dash);
	int year;

	if (yearStr.length() > 4)
		throw std::out_of_range(BAD_INPUT + date);

	std::istringstream(yearStr) >> year;
	if (year < 2009)
		throw std::out_of_range(BAD_INPUT + date);
	
	std::time_t t = time(NULL);
	struct tm *now = std::localtime(&t);
	if (year > now->tm_year + 1900)
		throw std::out_of_range(BAD_INPUT + date);
	return (year);
}

int BitcoinExchange::getMonth(std::string &date)
{
	std::string::iterator firstDash = std::find(date.begin(), date.end(), '-');
	std::string::iterator secondDash = std::find(firstDash + 1, date.end(), '-');
	std::string monthStr(firstDash + 1, secondDash);

	if (monthStr.length() > 2)
		throw std::out_of_range(BAD_INPUT + date);

	int month;
	std::istringstream(monthStr) >> month;
	
	if (month < 1 || month > 12)
		throw std::out_of_range(BAD_INPUT + date);
	
	return (month);
}

int	BitcoinExchange::getDay(std::string &date, int year, int month)
{
	std::string::iterator firstDash = std::find(date.begin(), date.end(), '-');
	std::string::iterator secondDash = std::find(firstDash + 1, date.end(), '-');
	std::string::iterator separator = std::find(secondDash + 1, date.end(), ' ');

	std::string dayStr(secondDash + 1, separator);

	if (dayStr.length() > 2)
		throw std::out_of_range(BAD_INPUT + date);
	
	int day;
	std::istringstream(dayStr) >> day;

	int thirtyDays[4] = {4, 6, 9, 11};
	int thirtyOneDays[7] = {1, 3, 5, 7, 8, 10, 11};

	if (std::find(thirtyDays, thirtyDays + 4, month) != thirtyDays + 4)
	{
		if (day > 30)
			throw std::out_of_range(BAD_INPUT + date);
	}

	if (std::find(thirtyOneDays, thirtyOneDays + 7, month) != thirtyOneDays + 7)
	{
		if (day > 31)
			throw std::out_of_range(BAD_INPUT + date);
	}

	if (month == 2)
	{
		if (day > (28 + this->isLeapYear(year)))
			throw std::out_of_range(BAD_INPUT + date);
	}

	return (day);
}

bool	BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void	BitcoinExchange::parseRatioDatabase(std::string &newStr) const
{
	bool point = false;

	std::string::iterator it = newStr.begin();
	if (it == newStr.end())
		throw std::invalid_argument("Error: corrupted database");
	while (it != newStr.end())
	{
		if (!isdigit(*it) && *it != '.')
			throw std::invalid_argument("Error: corrupted database");
		if (*it == '.' && point == true)
			throw std::invalid_argument("Error: corrupted database");
		if (*it == '.')
			point = true;
		it++;
	}
	long long int ratio;

	std::istringstream(newStr) >> ratio;
	if (ratio > INT_MAX)
		throw std::invalid_argument("Error: too large a number");
	if (ratio < 0)
		throw std::invalid_argument("Error: not a positive number");
	return;
}

void	BitcoinExchange::parseDateDatabase(std::string &dateStr)
{
	if (*(dateStr.end() - 1) == '-' || *dateStr.begin() == '-')
		throw std::invalid_argument(BAD_INPUT + dateStr);

	int nSlash = std::count(dateStr.begin(), dateStr.end(), '-');
	if (nSlash != 2)
		throw std::invalid_argument(BAD_INPUT + dateStr);
	
	if (dateStr.find("--") != std::string::npos)
		throw std::invalid_argument(BAD_INPUT + dateStr);

	std::string::iterator it = dateStr.begin();
	while(it != dateStr.end())
	{
		if (*it != '-' && !isdigit(*it))
			throw std::invalid_argument(BAD_INPUT + dateStr);
		it++;
	}
	try{
		getRealDate(dateStr);
	}catch(std::exception &e){
		throw;
	}
	return;
}