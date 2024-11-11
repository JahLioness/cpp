#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap(void);
		DiamondTrap &operator=(const DiamondTrap &diamondTrap);

		void	attack(std::string const &target);
		void	whoAmI(void);

	private:
		std::string _name;
} ;

#endif