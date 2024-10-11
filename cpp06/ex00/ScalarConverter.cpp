#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter(void) {
	return;
}
ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	*this = src;
	return;
}
ScalarConverter::~ScalarConverter(void) {
	return;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	if (this == &rhs){
		return (*this);
	}
	return (*this);
}

void ScalarConverter::convert(std::string type){

	bool (*isTypePtr[])(std::string &) = {&isInt, &isDouble, &isFloat, &isChar};
	void (*fromType[])(std::string &) = {&fromInt, &fromDouble, &fromFloat, &fromChar};

	if (isPseudoLiteral(type))
		return(fromPseudoLiteral(type));
	for (int i = 0; i < 4; i++){
		if ((*isTypePtr[i])(type) == 1){
			(*fromType[i])(type);
			return;
		}
	}
	std::cerr << "Error: Incorrect type format" << std::endl;
	return;
}

bool	isPseudoLiteral(std::string &type){
	if (type == "-inf"
		|| type == "+inf"
		|| type == "nan")
		return (1);
	if (type == "-inff"
		|| type == "+inff"
		|| type == "nanf")
		return (1);
	return (0);
}

void fromPseudoLiteral(std::string &type){

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (type == "nan" || type == "nanf")
	{
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
	else if (type == "+inf" || type == "+inff")
	{
		std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (type == "-inf" || type == "-inff")
	{
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
	return;

}

bool	isPrint(std::string &type){
	std::string::iterator it = type.begin();

	for(; it != type.end(); it++){
		if (*it < 32 || *it > 126)
			return 0;
	}
	return 1;
}

bool	isChar(std::string &type){
	std::string::iterator indexPtr;

	indexPtr = type.begin(); 
	if (*(indexPtr + 1) != 0)
		return 0;
	return 1;
}

bool	isInt(std::string &type){

	std::string::iterator it = type.begin();

	if (*it == '-')
		it++;
	for(; it != type.end(); it++)
	{
		if (*it < '0' || *it > '9')
			return 0;
	}
	return 1;
}

bool	isDouble(std::string &type){
	std::string::iterator it = type.begin();
	bool pointFlag = 0;

	if (*it == '-')
		it++;
	if (*it == '.')
		return 0;
	for(; it != type.end(); it++)
	{
		if ((*it < '0' || *it > '9') && *it != '.')
			return 0;
		if (*it == '.' && pointFlag == 1)
			return 0;
		if (*it == '.')
			pointFlag = 1;
	}
	if (*(it - 1) == '.')
		return 0;
	return 1;
}

bool	isFloat(std::string &type){
	std::string::iterator it = type.begin();
	bool pointFlag = 0;

	if (*it == '-')
		it++;
	if (*it == '.')
		return 0;
	while(it != type.end() && *it != 'f')
	{
		if ((*it < '0' || *it > '9') && *it != '.' && *it != 'f')
			return 0;
		if (*it == '.' && pointFlag == 1)
			return 0;
		if (*it == '.')
			pointFlag = 1;
		it++;
	}
	if (*it != 'f' || *(it + 1) != 0 || pointFlag == 0) 
		return 0;
	if (*(it - 1) == '.')
		return 0;
	return 1;
}

void fromInt(std::string &type){
	std::istringstream str(type);

	int number;

	str >> number;

	std::cout << "char: ";
	if (intOverflow(type))
		std::cout << "impossible" << std::endl;
	else if (number >= 32 && number <= 126)
		std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	if (intOverflow(type))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << number << std::endl;

	if (doubleOverflow(type))
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;

	if (floatOverflow(type))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
	return;
}

void fromDouble(std::string &type){
	std::istringstream str(type);

	double number;

	str >> number;
	
	std::cout << "char: ";
	if (intOverflow(type))
		std::cout << "impossible" << std::endl;
	else if (number >= 32 && number <= 126)
		std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	if (intOverflow(type))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	if (doubleOverflow(type))
		std::cout << "double: impossible" << std::endl;
	else if (static_cast<int>(number) == number)
		std::cout << "double: " << number << ".0" << std::endl;
	else
		std::cout << "double: " << number << std::endl;

	if (floatOverflow(type))
		std::cout << "float: impossible" << std::endl;
	else if (static_cast<int>(number) == number)
		std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;

	return;
}

void fromFloat(std::string &type){
	std::istringstream str(type);

	float number;

	str >> number;
	
	std::cout << "char: ";
	if (intOverflow(type))
		std::cout << "impossible" << std::endl;
	else if (number >= 32 && number <= 126)
		std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	if (intOverflow(type))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(number) << std::endl;

	if (doubleOverflow(type))
		std::cout << "double: impossible" << std::endl;
	else if (static_cast<int>(number) == number)
		std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(number) << std::endl;

	if (floatOverflow(type))
		std::cout << "float: impossible" << std::endl;
	else if (static_cast<int>(number) == number)
		std::cout << "float: " << number << ".0f" << std::endl;
	else
		std::cout << "float: " << number << "f" << std::endl;
	return;
}

void fromChar(std::string &type){
	std::istringstream str(type);

	char c = type[0];

	std::cout << "char: " << "'" << (c) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
}

bool intOverflow(std::string &type){
	std::istringstream str(type);

	double long checkOver;
	str >> checkOver;

	if (checkOver > std::numeric_limits<int>::max())
		return 1;
	if (checkOver < std::numeric_limits<int>::min())
		return 1;
	return 0;
}

bool floatOverflow(std::string &type){
	std::istringstream str(type);

	double long checkOver;
	str >> checkOver;

	if (checkOver > std::numeric_limits<float>::max())
		return 1;
	if (checkOver < -std::numeric_limits<float>::max())
		return 1;
	return 0;
}

bool doubleOverflow(std::string &type){
	std::istringstream str(type);

	double long checkOver;
	str >> checkOver;

	if (checkOver > std::numeric_limits<double>::max())
		return 1;
	if (checkOver < -std::numeric_limits<double>::max())
		return 1;
	return 0;
}
