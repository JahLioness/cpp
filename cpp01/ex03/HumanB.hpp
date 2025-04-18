#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon	*_arme;
	public:
	HumanB(std::string name);
	~HumanB(void);
	void setWeapon(Weapon &arme);
	void attack(void) const;
};

#endif