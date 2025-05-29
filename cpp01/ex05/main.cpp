#include "Harl.hpp"

int	main(void)
{
	std::string	level;
	Harl	plaignant;

	std::cout << "Welcome please select a level [DEBUG, INFO, WARNING, ERROR] so Harl can start complain" << std::endl;
	while (std::getline(std::cin, level))
	{
		if (level == "DEBUG" || level == "WARNING" || level == "ERROR" || level == "INFO")
		{
			plaignant.complain(level);
			std::cout << "Welcome please select a level [DEBUG, INFO, WARNING, ERROR] so Harl can start complain" << std::endl;
		}
		else
			std::cout << "Please enter DEBUG, INFO, WARNING or ERROR" << std::endl;
	}
		std::cout << "Thank you for using Harl, Goddbye !" << std::endl;
	return (0);
}
