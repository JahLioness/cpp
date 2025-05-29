#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>


class Span {
	private:
		std::vector<int> _tab;
		unsigned int	_N;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span &ref);
		Span &operator=(const Span &ref);
		~Span();
		std::vector<int> getTab();
		void addNumber(int num);
		void addNumber(std::vector<int> array);
		int	shortestSpan(void);
		int	longestSpan(void);
} ;

#endif