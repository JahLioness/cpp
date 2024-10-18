#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <map>

class ClapTrap
{
  public:
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &clapTrap);
	~ClapTrap();

protected:
	std::string _name;
	int _hitpoints;
	int _energyPoints;
	int _attackDamage;
	static	std::map<std::string, ClapTrap*> _clapTraps;
};

#endif