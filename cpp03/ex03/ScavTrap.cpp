#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " is born" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " is born" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap::ClapTrap(src)
{
	std::cout << "ScavTrap " << this->_name << " has copied from " << src._name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	ClapTrap::operator=(scavTrap);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " has died" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0 || this->_hitpoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " couldn't attack " << target << " it doesn't have enough hitpoints or energy points" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
