#include "Harl.hpp"

int	main(void)
{
	std::string	level;
	Harl	plaignant;

	std::cout << "Welcome please select a level [DEBUG, WARNING, ERROR, INFO] so Harl can start complain" << std::endl;
	while (std::getline(std::cin, level))
	{
		if (level == "DEBUG" || level == "WARNING" || level == "ERROR" || level == "INFO")
		{
			plaignant.complain(level);
			std::cout << "Welcome please select a level [DEBUG, WARNING, ERROR, INFO] so Harl can start complain" << std::endl;
		}
		else
			std::cout << "Please enter DEBUG, WARNING, ERROR or INFO" << std::endl;
	}
	return (0);
}