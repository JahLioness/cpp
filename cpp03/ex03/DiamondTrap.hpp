#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
	public:
		DiamondTrap(std::string name);
		~DiamondTrap(void);
		void	attack(std::string const &target);
		void	whoAmI(void);

	private:
		std::string _name;
} ;

#endif