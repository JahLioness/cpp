#include "ScalarConverter.hpp"
#include <stdio.h>

void ScalarConverter::convert(std::string const toConvert) {
	char c;
	int val;
	float valF;
	double valD;
	try
	{
		converter(toConvert, &c, &val, &valF, &valD);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	print(toConvert, c, val, valF, valD);
}

bool ScalarConverter::isChar(std::string const toConvert) {
	return (toConvert.length() == 1 && !isdigit(toConvert[0]));
}

bool ScalarConverter::isInt(std::string const toConvert) {
	for(size_t i = 0; i < toConvert.length(); i++) {
		if (!isdigit(toConvert[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloat(std::string const toConvert) {
	if (toConvert.find('.') == std::string::npos || toConvert.find('f') == std::string::npos)
		return (false);
	for(size_t i = 0; i < toConvert.length(); i++) {
		if ((!isdigit(toConvert[i]) && toConvert[i] != '.' && i != (toConvert.length() - 1)) || (i == (toConvert.length() - 1) && toConvert[i] != 'f'))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isDouble(std::string const toConvert) {
	if (toConvert.find('.') == std::string::npos)
		return (false);
	for (size_t i = 0; i < toConvert.length(); i++) {
		if (!isdigit(toConvert[i]) && toConvert[i] != '.')
			return (false);
	}
	return (true);
}

bool ScalarConverter::isNan(std::string const toConvert) {
	return (toConvert == "nan" || toConvert == "nanf");
}

bool ScalarConverter::isInf(std::string const toConvert) {
	return (toConvert == "-inf" || toConvert == "+inf");
}

void	ScalarConverter::converter(std::string const toConvert, char *c, int *val, float *valF, double *valD) {
	std::stringstream strm(toConvert);
	if (isChar(toConvert))
	{
		*c = toConvert[0];
		*val = static_cast<int>(toConvert[0]);
		*valF  = static_cast<float>(toConvert[0]);
		*valD = static_cast<double>(toConvert[0]);
	}
	else if (isInt(toConvert))
	{
		strm >> *val;
		*c = static_cast<char>(*val);
		*valF = static_cast<float>(*val);
		*valD = static_cast<double>(*val);
	}
	else if (isFloat(toConvert) && !isNan(toConvert) && !isInf(toConvert))
	{
		strm >> *valF;
		*c = static_cast<char>(*valF);
		*val = static_cast<int>(*valF);
		*valD = static_cast<double>(*valF);
	}
	else if (isDouble(toConvert) && !isNan(toConvert) && !isInf(toConvert))
	{
		strm >> *valD;
		*c = static_cast<char>(*valD);
		*val = static_cast<int>(*valD);
		*valF = static_cast<float>(*valD);
	}
}

void	ScalarConverter::print(std::string const toConvert, char c, int val, float valF, double valD) {
	std::cout << "char: ";
	if (isNan(toConvert) || isInf(toConvert) || c < 0 || c > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "Non displayable" <<std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: " ;
	if (isNan(toConvert) || isInf(toConvert))
		std::cout << "impossible" << std::endl;
	else
		std::cout << val << std::endl;
	std::cout << "float: ";
	if (isNan(toConvert))
		std::cout << "nanf" << std::endl;
	else if (isInf(toConvert))
	{
		if (toConvert[0] == '+')
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(POS_INF) << "f" << std::endl;
		else if (toConvert[0] == '-')
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(NEG_INF) << "f" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << valF << "f" << std::endl;
	std::cout << "double: ";
	if (isNan(toConvert))
		std::cout << "nan" << std::endl;
		else if (isInf(toConvert))
		{
			if (toConvert[0] == '+')
				std::cout << std::fixed << std::setprecision(1) << POS_INF << std::endl;
			else if (toConvert[0] == '-')
				std::cout << std::fixed << std::setprecision(1) << NEG_INF << std::endl;
		}
	else
		std::cout << std::fixed << std::setprecision(1) << valD << std::endl;	
}
