#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jorris = ClapTrap("jorris");
	ClapTrap	teddy = ClapTrap(jorris);

	teddy.attack("jorris");
	jorris.takeDamage(0);
	jorris.beRepaired(5000000);
	jorris.attack("jorris_clone");
	teddy.takeDamage(0);
	teddy.beRepaired(0);
}
