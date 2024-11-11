#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	this->_arme = NULL;
}

HumanB::~HumanB(void)
{
	
}

void	HumanB::setWeapon(Weapon &arme)
{
	this->_arme = &arme;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name + " attacks with their " + this->_arme->getType() << std::endl;
}
