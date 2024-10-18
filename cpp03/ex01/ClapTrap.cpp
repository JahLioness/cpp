#include "ClapTrap.hpp"

std::map<std::string, ClapTrap*> ClapTrap::_clapTraps;

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_clapTraps[this->_name] = this;
	std::cout << "ClapTrap " << name << " has born" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	this->_clapTraps.erase(this->_name);
	std::cout << "ClapTrap " << this->_name << " has died" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	this->_clapTraps[this->_name] = this;
	std::cout << "Claptrap " << this->_name << " has copied " << src._name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	this->_name = clapTrap._name + "_clone";
	this->_hitpoints = clapTrap._hitpoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
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
	std::map<std::string, ClapTrap*>::iterator	foe = this->_clapTraps.find(target);
	if (foe != this->_clapTraps.end())
	{
		ClapTrap*	foePtr = foe->second;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		foePtr->takeDamage(this->_attackDamage);
	}
	else
		std::cout << "ClapTrap " << target << " is not in the wild..." << std::endl;
}
