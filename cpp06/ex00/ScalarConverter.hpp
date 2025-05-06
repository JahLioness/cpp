#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cctype>
# include <cmath>
# include <iomanip>
# include <iostream>
# include <limits>
# include <string>
# include <stdlib.h>

# define POS_INF (std::numeric_limits<double>::infinity())
# define NEG_INF (std::numeric_limits<double>::infinity() * -1)
# define MAX_INT (std::numeric_limits<int>::max())
# define MIN_INT (std::numeric_limits<int>::min())

class ScalarConverter
{
  private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter &operator=(const ScalarConverter &ref);

  public:
	static void convert(std::string const toConvert);
	static bool isChar(std::string const toConvert);
	static bool isInt(std::string const toConvert);
	static bool isFloat(std::string const toConvert);
	static bool isDouble(std::string const toConvert);
	static bool isNan(std::string const toConvert);
	static bool isInf(std::string const toConvert);
	static void converter(std::string const toConvert, char *c, int *val, float *valF, double *valD);
	static void	print(std::string const toConvert, char c, int val, float valF, double valD);

};

#endif