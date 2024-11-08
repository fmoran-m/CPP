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

		std::vector<std::pair<unsigned int, unsigned int> > pairNumbers(bool lastElementExists);
		void sortPairs(std::vector<std::pair<unsigned int, unsigned int> > &pairVector);
		void sortLargerNumbers(std::vector<std::pair<unsigned int, unsigned int> > &pairVector);
		void mergeSort(std::vector<std::pair<unsigned int, unsigned int> > &pairVector, size_t begin, size_t end);
		void merge(std::vector<std::pair<unsigned int, unsigned int> > &pairVector, size_t begin, size_t mid, size_t end);
};
#endif