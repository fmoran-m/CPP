#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <ctime>
# include <map>
# include <string>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		~BitcoinExchange(void);

		void	loadDatabase(void);
		void	parseInput(std::string const argvStr);
	private:

		std::map<std::string, float> dataBase;
		void	storeData(std::string line);

};
#endif
