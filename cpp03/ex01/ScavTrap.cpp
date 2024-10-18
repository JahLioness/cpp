#include "ScavTrap.hpp"

ScavTrap::ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_clapTraps[this->_name] = this;
	std::cout << "ScavTrap " << name << " has born" << std::endl;
}

ScavTrap::ClapTrap::~ClapTrap(void)
{
	this->_clapTraps.erase(this->_name);
	std::cout << "ScavTrap " << this->_name << " has died" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
