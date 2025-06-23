#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::fstream data;
		std::fstream infile;
		data.open("data.csv", std::fstream::in);
		if (!data.is_open())
		{
			std::cout << "Couldn't open database file" << std::endl;
			return (0);
		}
		infile.open(av[1], std::fstream::in);
		if (infile.is_open())
		{
			BitcoinExchange *btc = new BitcoinExchange();
			std::pair<std::map<std::string, float>::iterator,bool> ret;
			std::string line;
			while (std::getline(infile, line, '|'))
			{		
				std::cout << line << std::endl;
			}
			std::cout << "file openning is ok" << std::endl;
			data.close();
			delete btc;
		}
		else
			std::cout << "Can't open file " << av[1] << std::endl;
	}
	else
		std::cout << "Please enter one filename as programm's argument" << std::endl;
	return (0);
}
