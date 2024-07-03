#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arme): name(name), arme(arme)
{

}

HumanA::~HumanA(void)
{

}

void	HumanA::attack(void) const
{
	std::cout << this->name + " attacks with their " + this->arme.getType() << std::endl;
}
