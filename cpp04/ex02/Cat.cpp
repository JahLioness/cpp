#include "Cat.hpp"

Cat::Cat(void) : _type("Cat")
{
	std::cout << "Look how cute this " + this->_type + " is and it just born" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal::Animal(src)
{
	std::cout << "This is a cat is type is " << this->_type << " it has copied from a type " << src._type << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		delete this->_brain;
		this->_brain = cat._brain;
		this->_type = cat._type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Oh noooo the little " + this->_type + " is dead" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

std::string Cat::getType(void) const
{
	return (this->_type);
}
