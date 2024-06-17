#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact Initialized" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact Destructed" << std::endl;
}

std::string	Contact::getFirstname(void) const
{
	return (this->first_name);
}

std::string Contact::getLastname(void) const
{
	return (this->last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}

void Contact::setFirstname(const std::string firstName)
{
	this->first_name = firstName;
}

void Contact::setLastname(const std::string lastName)
{
	this->last_name = lastName;
}

void Contact::setNickname(const std::string nickName)
{
	this->nickname = nickName;
}

void Contact::setPhoneNumber(const std::string phoneNumber)
{
	this->phone_number = phoneNumber;
}

void Contact::setDarkestSecret(const std::string darkestSecret)
{
	this->darkest_secret = darkestSecret;
}
