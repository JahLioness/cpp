#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap " << _name << " is born" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " is born" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap::ClapTrap(src)
{
	std::cout << "FragTrap " << this->_name << " has copied from " << src._name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
	ClapTrap::operator=(fragTrap);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " has died" << std::endl;
}

void	FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " has high fived" << std::endl;
}
