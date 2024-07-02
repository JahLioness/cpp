#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook Initialized" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructed" << std::endl;
}

void PhoneBook::add(int i)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	if (i > 7)
		i = 0;
	while (lastName.empty())
	{
		std::cout << "Last Name: " << std::ends;
		if (!getline(std::cin, lastName))
		{
			std::cout << "You exited the programm" << std::endl;
			exit(EXIT_SUCCESS);
		}
		// std::getline(std::cin, lastName);
		if (lastName.empty())
			std::cout << "Error no empty entry" << std::endl;
		else
			this->toto[i].setLastname(lastName);
	}
	while (firstName.empty())
	{
		std::cout << "First Name: " << std::ends;
		if (!getline(std::cin, firstName))
		{
			std::cout << "You exited the programm" << std::endl;
			exit(EXIT_SUCCESS);
		}
		if (firstName.empty())
			std::cout << "Error no empty entry" << std::endl;
		else
			this->toto[i].setFirstname(firstName);
	}
	while (nickname.empty())
	{
		std::cout << "Nickname: " << std::ends;
		if (!getline(std::cin,nickname))
		{
			std::cout << "You exited the programm" << std::endl;
			exit(EXIT_SUCCESS);
		}
		if (nickname.empty())
			std::cout << "Error no empty entry" << std::endl;
		else
			this->toto[i].setNickname(nickname);
	}
	while (phoneNumber.empty() || phoneNumber.find_first_of("0123456789"))
	{
		std::cout << "Phone Number: " << std::ends;
		if (!getline(std::cin, phoneNumber))
		{
			std::cout << "You exited the programm" << std::endl;
			exit(EXIT_SUCCESS);
		}
		if (phoneNumber.empty())
			std::cout << "Error no empty entry" << std::endl;
		else if (phoneNumber.find_first_of("0123456789"))
			std::cout << "Error entry must be digits" << std::endl;
		else
			this->toto[i].setPhoneNumber(phoneNumber);
	}
	while (darkestSecret.empty())
	{
		std::cout << "Darkest Secret: " << std::ends;
		if (!getline(std::cin, darkestSecret))
		{
			std::cout << "You exited the programm" << std::endl;
			exit(EXIT_SUCCESS);
		}
		if (darkestSecret.empty())
			std::cout << "Error no empty entry" << std::endl;
		else
			this->toto[i].setDarkestSecret(darkestSecret);
	}
}

void	PhoneBook::search(void) const
{
	int	i;
	std::string empty_tab;
	std::string index;
	std::stringstream ss;

	i = 0;
	std::cout << "Index     |First Name|Last Name |Nickname " << std::endl;
	while (i < 8)
	{
		empty_tab = "          |          |          |          ";
		ss << i;
		empty_tab.replace(0, 1, ss.str());
		if (this->toto[i].getFirstname().length() > 10)
			empty_tab.replace(11, 10, this->toto[i].getFirstname().substr(0, 9) + ".");
		else
			empty_tab.replace(11, this->toto[i].getFirstname().length(), this->toto[i].getFirstname());
		if (this->toto[i].getLastname().length() > 10)
			empty_tab.replace(22, 10, this->toto[i].getLastname().substr(0, 9) + ".");
		else
			empty_tab.replace(22, this->toto[i].getLastname().length(), this->toto[i].getLastname());
		if (this->toto[i].getNickname().length() > 10)
			empty_tab.replace(33, 10, this->toto[i].getNickname().substr(0, 9) + ".");
		else
			empty_tab.replace(33, this->toto[i].getNickname().length(), this->toto[i].getNickname());
		std::cout << empty_tab << std::endl;
		i++;
		ss.str("");
		
	}
	std::cout << std::endl;
	while (index.empty() || index.find_first_of("01234567"))
	{
		std::cout << "Please enter an index : ";
		if (!getline(std::cin, index))
		{
			std::cout << "You exited the program" << std::endl;
			return ;
		}
		if (index.find_first_of("01234567"))
			std::cout << "Index must be digit between 0 and 7" << std::endl;
		else if (index.empty())
			std::cout << "Entry must not be empty" << std::endl;
		else
		{
			i = std::atoi(index.c_str());
			if (i > 7)
			{
				std::cout << "Index must be digit between 0 and 7" << std::endl;
				index.clear();
			}
			else if (this->toto[i].getFirstname().empty())
			{
				std::cout << "No entry on this index" << std::endl;
				index.clear();
			}
			else
			{
				std::cout << "First name : " + this->toto[i].getFirstname() << std::endl;
				std::cout << "Last name : " + this->toto[i].getLastname() << std::endl;
				std::cout << "Nickname : " + this->toto[i].getNickname() << std::endl;
				std::cout << "Phone Number : " + this->toto[i].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret : " + this->toto[i].getDarkestSecret() << std::endl;
				break ;
			}
		}
	}
}
