#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <ctime>
# include <map>
# include <string>

# define FORMAT_ERROR "Error: format does not match"
# define BAD_INPUT "Error: bad input => "

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);

		void	loadDatabase(void);
		void	loadInput(char *argvStr);
	private:

		std::map<std::string, float> dataBase;

		size_t			findSeparator(std::string const &line);
		void			storeData(std::string line);
		void			parseDate(std::string::iterator &pipe, std::string &newStr);
		void			parseRatio(std::string::iterator &pipe, std::string &newStr) const;
		void			lineConversion(std::string const line);
		void			printConversion(std::string &newStr, std::string::iterator &pipe);
		struct tm		getRealDate(std::string &newStr);

		int				getYear(std::string &date);
		int				getMonth(std::string &date);
		int				getDay(std::string &date, int year, int month);
		bool			isLeapYear(int year);
};
#endif
