#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter &operator=(ScalarConverter const &rhs);
		~ScalarConverter(void);
	public:
		static void convert(std::string type);
};

void	fromNumber(std::string &type);
bool	isPrint(std::string &type);
bool	isChar(std::string &type);
bool	isInt(std::string &type);
bool	isDouble(std::string &type);
bool	isFloat(std::string &type);
void	fromInt(std::string &type);
void	fromDouble(std::string &type);
void	fromFloat(std::string &type);
void	fromChar(std::string &type);
bool	isPseudoLiteral(std::string &type);
void	fromPseudoLiteral(std::string &type);
bool	intOverflow(std::string &type);
bool	floatOverflow(std::string &type);
bool	doubleOverflow(std::string &type);
#endif
