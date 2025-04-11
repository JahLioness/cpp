#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	jorris = ClapTrap("jorris");
	ScavTrap	teddy = ScavTrap("teddy");

	teddy.guardGate();
	teddy.attack("jorris");
	jorris.takeDamage(20);
	jorris.beRepaired(5000000);
	jorris.attack("teddy");
	teddy.takeDamage(0);
	teddy.beRepaired(0);
}
