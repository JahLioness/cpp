#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange 
{
	private:
		std::map<std::string, float> _values;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &ref);
		BitcoinExchange &operator=(const BitcoinExchange &ref);
		~BitcoinExchange();

} ;

#endif