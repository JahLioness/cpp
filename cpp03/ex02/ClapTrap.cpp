#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << _name << " is born" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << name << " is born" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " has died" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "Claptrap " << this->_name << " has copied " << src._name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	if (this != &clapTrap)
	{
		this->_name = clapTrap._name + "_clone";
		this->_hitpoints = clapTrap._hitpoints;
		this->_energyPoints = clapTrap._energyPoints;
		this->_attackDamage = clapTrap._attackDamage;
	}
	return (*this);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints <= 0)
		return ;
	if ((this->_hitpoints - amount) < 0)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " damages, his hitpoints are now about " << this->_hitpoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints <= 0 || this->_energyPoints <=0)
		return ;
	this->_hitpoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " has restored " << amount << " hitpoints and is now at " << this->_hitpoints << " hitpoints" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0 || this->_hitpoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}
