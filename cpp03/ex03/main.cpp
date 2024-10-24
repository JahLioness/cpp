#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	jorris = ClapTrap("jorris");
	DiamondTrap	teddy = DiamondTrap("teddy");

	teddy.highFivesGuys();
	teddy.whoAmI();
	teddy.attack("jorris");
}
