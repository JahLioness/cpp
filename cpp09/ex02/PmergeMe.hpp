#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <string>
#include <climits>
#include <cstdlib>
#include <ctime>

class PmergeMe {
	private:
		std::vector<unsigned int> _vec;
		std::deque<unsigned int> _deq;
	public:
		PmergeMe(std::vector<unsigned int> vec, std::deque<unsigned int> deq);
		PmergeMe(const PmergeMe &ref);
		PmergeMe &operator=(const PmergeMe &ref);
		~PmergeMe();
		void sortVec(std::vector<unsigned int> &tab);
		void sortDeq(std::deque<unsigned int> &tab);
		bool isSorted(std::vector<unsigned int> &vec);
		bool isSorted(std::deque<unsigned int> &deq);
		void process(void);
		std::vector<unsigned int> jacobI(size_t pendSize);
} ;