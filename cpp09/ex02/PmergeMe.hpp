#pragma once

#include <iostream>
#include <vector>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &ref);
		PmergeMe &operator=(const PmergeMe &ref);
		~PmergeMe();
} ;