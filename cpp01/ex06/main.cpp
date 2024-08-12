#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	plaignant;
	std::string	key[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	if (ac == 2)
	{
		std::string	level = av[1];
		while (i < 4)
		{
			if (key[i] == level)
					break;
			i++;
		}
		switch (i)
		{
			case 0:
				std::cout << "[ DEBUG ]" << std::endl;
				plaignant.complain("DEBUG");
				std::cout << std::endl;
			case 1:
				std::cout << "[ INFO ]" << std::endl;
				plaignant.complain("INFO");
				std::cout << std::endl;
			case 2:
				std::cout << "[ WARNING ]" << std::endl;
				plaignant.complain("WARNING");
				std::cout << std::endl;
			case 3:
				std::cout << "[ ERROR ]" << std::endl;
				plaignant.complain("ERROR");
				std::cout << std::endl;
				break;
			default:
				break;
		}
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return (0);
}