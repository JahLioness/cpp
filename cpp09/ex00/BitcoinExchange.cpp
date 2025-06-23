#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
	*this = ref;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
	if (this != &ref)
	{
		_values.erase(_values.begin(), _values.end());
		_values.insert(ref._values.begin(), ref._values.end());
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}