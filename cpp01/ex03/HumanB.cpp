#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{
	this->arme = NULL;
}

HumanB::~HumanB(void)
{
	
}

void	HumanB::setWeapon(Weapon &arme)
{
	this->arme = &arme;
}

void	HumanB::attack(void) const
{
	std::cout << this->name + " attacks with their " + this->arme->getType() << std::endl;
}
