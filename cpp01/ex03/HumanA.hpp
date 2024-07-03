#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon 		&arme;
	public:
		HumanA(std::string name, Weapon &arme);
		~HumanA(void);
		void attack(void) const;
};

#endif