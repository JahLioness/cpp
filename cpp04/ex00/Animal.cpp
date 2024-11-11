#include "Animal.hpp"

Animal::Animal(void) : _type("Original")
{
	std::cout << "An Animal of " + this->_type + " type just born" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "An Animal of " + this->_type + " type just born" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal of type " << this->_type << " has copied from animal " << src._type << std::endl; 
}

Animal &Animal::operator=(const Animal &animal)
{
	this->_type = animal._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "An Animal of " + this->_type + " type just died" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "OOOOOooouuuuuh" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
