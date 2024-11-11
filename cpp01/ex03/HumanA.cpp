#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arme): _name(name), _arme(arme)
{

}

HumanA::~HumanA(void)
{

}

void	HumanA::attack(void) const
{
	std::cout << this->_name + " attacks with their " + this->_arme.getType() << std::endl;
}
