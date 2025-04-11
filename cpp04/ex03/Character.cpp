#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	for (int i = 0; i < 1024; i++)
		this->_dump[i] = 0;
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
	for (int i = 0; i < 1024; i++)
		if (this->_dump[i])
			delete this->_dump[i];
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
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
	{
		for (int i = 0; i < 1024; i++)
		{
			if (this->_dump[i] == NULL)
			{
				this->_dump[i] = this->_inventory[idx];
				this->_inventory[idx] = NULL;
				break ;
			}
		}
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
