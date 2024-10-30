#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <ctime>
# include <map>
# include <string>

# define FORMAT_ERROR "Error: format does not match"

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
		std::map<std::string, float> inputData;

		void		storeData(std::string line);
		void		parseDate(std::string::iterator pipe, std::string newStr) const;
		void		parseRatio(std::string newStr) const;
		void		printLineConversion(std::string const line);
		void		dateValueToMap(std::string newStr, std::string::iterator pipe);
};
#endif
