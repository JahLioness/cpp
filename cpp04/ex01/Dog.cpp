#include "Dog.hpp"

Dog::Dog(void) : Animal::Animal("Dog")
{
	std::cout << "This should be an animal of type " + this->_type + " and it just born" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal::Animal(src)
{
	std::cout << "This is a dog of type " << this->_type << " it has copied from an animal of type " << src._type << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	Animal::operator=(dog);
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "We sadly announce the death of a " + this->_type << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf !" << std::endl;
}

std::string Dog::getType(void) const
{
	return (this->_type);
}
