#include "Span.hpp"

Span::Span(unsigned int N): _N(N) {};

Span::Span(const Span &ref) {
	*this = ref;
}

Span::~Span() {
	_tab.clear();
}

Span &Span::operator=(const Span &ref) {
	if (this != &ref)
	{
		_tab.clear();
		_N = ref._N;
		_tab = ref._tab;
	}
	return (*this);
}

void	Span::addNumber(int num) {
	std::vector<int>::iterator begin = _tab.begin();
	std::vector<int>::iterator end = _tab.end();
	if (std::distance(begin, end) >= _N)
		throw std::runtime_error("Container already at full capacity");
	else
		_tab.push_back(num);
}

void	Span::addNumber(std::vector<int> array) {
	if (_tab.size() + array.size() > _N)
		throw std::runtime_error("Not enough places left to add values");
	_tab.insert(_tab.end(), array.begin(), array.end());
}

int	Span::shortestSpan(void) {
	if (_tab.size() <= 1)
		throw std::runtime_error("Container is empty or has just one value");
	std::vector<int>::iterator begin = _tab.begin();
	std::vector<int>::iterator end = _tab.end();
	std::sort(begin, end);
	std::vector<int>::iterator next;
	std::vector<int>::iterator min = begin;
	std::vector<int>::iterator minNext = begin + 1;
	for (std::vector<int>::iterator it = begin + 1; it != end; it++)
	{
		next = it;
		for (std::vector <int>::iterator ite = it + 1; ite != end; ite ++)
		{
			if (*ite - *next < *minNext - *min)
			{
				minNext = ite;
				min = next;
			}
		}
	}
	return (*minNext - *min);
}

int	Span::longestSpan(void) {
	if (_tab.size() <= 1)
		throw std::runtime_error("Container is empty or has just one value");
	std::vector<int>::iterator begin = _tab.begin();
	std::vector<int>::iterator end = _tab.end();
	std::sort(begin, end);
	return (*(end - 1) - *begin);
}

std::vector<int> Span::getTab(void) {
	return (_tab);
}