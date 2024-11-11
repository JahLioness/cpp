#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "Look how strange a " << this->_type << " animal juste born" <<std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal::WrongAnimal(src)
{
	std::cout << this->_type << " has just copied from " << src._type << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Sadly this " << this->_type << " just died" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	WrongAnimal::operator=(wrongCat);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaouuuuu !" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return (this->_type);
}
