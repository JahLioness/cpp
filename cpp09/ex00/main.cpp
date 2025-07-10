#include "BitcoinExchange.hpp"

bool is_empty(std::fstream& infile)
{
	return infile.peek() == std::ifstream::traits_type::eof();
}

bool ft_check_date(std::string line)
{
	if (line[4] != '-' || line[7] != '-')
		return (0);
	char *check;

	double day = std::strtod(line.substr(8).c_str(), &check);
	double month = std::strtod(line.substr(line.find('-') + 1, line.find('-') - 2).c_str(), &check);
	double year = std::strtod(line.substr(0, line.find('-')).c_str(), &check);
	if (*check)
		return (0);
	else if (day < 1 || day > 31 || month < 1 || month > 12 || year < 2009 || year > 2025 || (month == 2 && day > 28 && year != 2012 && year != 2016 && year != 2020 && year != 2024))
		return (0);
	else if (day == 29 && month == 2 && (year == 2012 || year == 2016 || year == 2020 || year == 2024))
		return (1);
	return (1);
}

bool ft_check_extension(char *filename)
{
	std::string to_check = filename;
	if (to_check.find('.') == (to_check.size() - 4))
	{
		if (to_check.substr(to_check.find('.') + 1) == "txt")
			return (1);
		return (0);
	}
	return (0);
}

void ft_trim(std::string &line)
{
	for (size_t i = 0; i < line.size();)
	{
		if (isspace(line[i]))
			line.erase(i, 1);
		else
			++i;
	}
}

void	ft_split_line(BitcoinExchange *btc, std::string line, bool &header)
{
	ft_trim(line);
	if (line == "date,exchange_rate" && !header)
	{
		header = 1;
		return ;
	}
	else if (line == "date,exchange_rate" && header)
		throw std::runtime_error("Double header, invalid file");
	else if (line.empty())
		return ;
	std::string date = line.substr(0, line.find(','));
	char *check;
	double value = std::strtod(line.substr(line.find(',') + 1).c_str(), &check);
	if (*check)
		throw std::runtime_error("Incorrect value");
	else if (!ft_check_date(date))
		throw std::runtime_error("Invalid date format");
	else
		btc->_values.insert(std::pair<std::string, double>(date, value));
	
}

std::string getDate(std::string line, bool &header)
{
	if (line == "date|value" && !header)
	{
		header = 1;
		return "\0";
	}
	else if (line == "date|value" && header)
		throw std::runtime_error("Double header, invalid file");
	else if (line.empty())
		return "\0";
	else
	{
		std::string date = line.substr(0, line.find('|'));
		return (date);
	}
}

double getValue(std::string line)
{
	if (line.empty())
		return -1;
	else
	{
		if (line.substr(line.find('|') + 1) != line && line != "date|value")
		{
			char *check;
			double value = std::strtod(line.substr(line.find('|') + 1).c_str(), &check);
			if (*check)
				throw std::runtime_error("Incorrect value");
			else if (value < 0)
				throw std::runtime_error("Error: not a positive number.");
			else if (value > 1000)
				throw std::runtime_error("Error: too large a number.");
			return (value);
		}
		else
			return (1001);
	}
}

void ft_compare(BitcoinExchange *btc, std::string date, double value)
{
	std::map<std::string, double>::iterator itLow = btc->_values.lower_bound(date);
	for (std::map<std::string, double>::iterator it = btc->_values.begin(); it != btc->_values.end(); it ++)
	{
		if (it == itLow)
		{
			if (value < 1000)
				std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			else
				std::cerr << "Error: bad input => " << date << std::endl;
		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		std::fstream data;
		std::fstream infile;
		data.open("data.csv", std::fstream::in);
		if (!data.is_open())
		{
			std::cerr << "Couldn't open database file" << std::endl;
			return (1);
		}
		else if (is_empty(data))
		{
			std::cerr << "File is empty" << std::endl;
			data.close();
			return (1);
		}
		if (!ft_check_extension(av[1]))
		{
			std::cerr << "Wrong type of file, only \".txt\" files are accepted" << std::endl;
			data.close();
			return (1);
		}
		infile.open(av[1], std::fstream::in);
		if (infile.is_open())
		{
			BitcoinExchange *btc = new BitcoinExchange();
			std::string line;
			bool header = 0;
			while (std::getline(data, line))
			{
				try
				{
					ft_split_line(btc, line, header);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
			header = 0;
			while (std::getline(infile, line))
			{
				try
				{
					ft_trim(line);
					if (!line.empty())
					{
						std::string date = getDate(line, header);
						double value = getValue(line);
						if (!date.empty() && value >= 0)
						{
							if (ft_check_date(date) && value < 1001)
								ft_compare(btc, date, value);
							else
								std::cerr << "Error: bad input => " << date << std::endl;
						}
					}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				
			}
			data.close();
			infile.close();
			delete btc;
		}
		else
			std::cerr << "Can't open file " << av[1] << std::endl;
	}
	else
		std::cerr << "Please enter one filename as programm's argument" << std::endl;
	return (0);
}
