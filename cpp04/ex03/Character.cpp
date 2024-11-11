#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{

}

Character::Character(const Character &src)
{
	*this = src;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
}

Character &Character::operator=(const Character &character)
{
	if (this != &character)
	{
		this->_name = character._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = character._inventory[i];
		}
	}
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	
}