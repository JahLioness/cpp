#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook repertoire;
	int i;
	std::string entry;


	i = 0;
	std::cout << "Welcome to the phone book, please type ADD, SERACH or EXIT" << std::endl;
	while (std::getline(std::cin, entry))
	{
		if (entry == "ADD")
		{
			repertoire.add(i);
			i++;
		}
		else if (entry == "SEARCH")
			repertoire.search();
		else if (entry == "EXIT")
			break ;
	}
	return (0);
}
