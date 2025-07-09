#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <exception>
#include <stdlib.h>

class BitcoinExchange 
{
	private:
	public:
		std::map<std::string, double> _values;
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		~BitcoinExchange();

} ;

#endif