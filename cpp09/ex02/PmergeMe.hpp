/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:59 by fmoran-m          #+#    #+#             */
/*   Updated: 2024/11/22 13:51:02 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe {
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe(void);

		void parseInput(std::string &argvStr);
		void applyVectorAlgorithm(void);
		void applyDequeAlgorithm(void);
		float getTime(void);

		std::vector<unsigned int>	getNumbersVector(void);
		std::deque<unsigned int>	getNumbersDeque(void);
	
	private:

		std::vector<unsigned int>	numbersVector;
		std::deque<unsigned int>	numbersDeque;

		//Vector algorithm
		std::vector<std::pair<unsigned int, unsigned int> > pairNumbers(bool lastElementExists);
		void sortPairs(std::vector<std::pair<unsigned int, unsigned int> > &pairVector);
		void sortLargerNumbers(std::vector<std::pair<unsigned int, unsigned int> > &pairVector);
		void mergeSort(std::vector<std::pair<unsigned int, unsigned int> > &pairVector, size_t begin, size_t end);
		void merge(std::vector<std::pair<unsigned int, unsigned int> > &pairVector, size_t begin, size_t mid, size_t end);
		std::vector<unsigned int> sortVector(std::vector<std::pair<unsigned int, unsigned int> > &pairVector);
		std::vector<unsigned int> generateJacobsthal(size_t size);
		void jacobInsertion(std::vector<unsigned int>::iterator jacobIt, std::vector<unsigned int> &pend, std::vector<unsigned int> &sortedVector);

		//Deque Algorithm
		std::deque<std::pair<unsigned int, unsigned int> > pairNumbersDeque(bool lastElementExists);
		void sortPairsDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque);
		void sortLargerNumbersDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque);
		void mergeSortDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque, size_t begin, size_t end);
		void mergeDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque, size_t begin, size_t mid, size_t end);
		std::deque<unsigned int> sortDeque(std::deque<std::pair<unsigned int, unsigned int> > &pairDeque);
		std::deque<unsigned int> generateJacobsthalDeque(size_t size);
		void jacobInsertionDeque(std::deque<unsigned int>::iterator jacobIt, std::deque<unsigned int> &pendDeque, std::deque<unsigned int> &sortedDeque);
};
#endif
