#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Original")
{
	std::cout << "Wrong Animal of type " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Wrong Animal of type " << this->_type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "Wrong Animal of type " << this->_type << " has copied from Wrong Animal of type " << src._type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
{
	this->_type = wrongAnimal._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal of type " << this->_type << " just died" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "OOOOOooooooooh !" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}
