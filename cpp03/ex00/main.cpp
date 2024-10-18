#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	jorris = ClapTrap("jorris");
	ClapTrap	teddy = ClapTrap(jorris);

	teddy.attack("jorris");
	jorris.beRepaired(5000000);
	jorris.attack("jorris_clone");
	teddy.beRepaired(0);
}