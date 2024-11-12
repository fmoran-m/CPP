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
		std::vector<unsigned int> sortVector(std::vector<std::pair<unsigned int, unsigned int> > &pairVector);
		std::vector<unsigned int> generateJacobsthal(size_t size);
		void jacobInsertion(std::vector<unsigned int>::iterator jacobIt, std::vector<unsigned int> &jacobsthalSequence, std::vector<unsigned int> &pend, std::vector<unsigned int> &sortedVector);
		void binarySearch(unsigned int n, std::vector<unsigned int> &sortedVector, unsigned int index);
		void binarySearchInsertion(std::vector<unsigned int> sortedVector, unsigned int low, unsigned int high, unsigned int n);
};
#endif