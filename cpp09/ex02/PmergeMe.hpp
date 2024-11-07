#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <string>

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe(void);

		void parseInput(std::string &argvStr);
		void applyAlgorithm(void);
	
	private:
		std::vector<unsigned int>	numbersVector;
		std::list<unsigned int>		numbersList;

		std::vector<std::pair<unsigned int, unsigned int>> pairNumbers(bool lastElementExists);
		std::vector<std::pair<unsigned int, unsigned int>> sortPairs(std::vector<std::pair<unsigned int, unsigned int>> pairVector);
		std::vector<std::pair<unsigned int, unsigned int>> sortLargerNumbers(std::vector<std::pair<unsigned int, unsigned int>> pairVector);
};
#endif
