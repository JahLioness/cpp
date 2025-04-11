#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	jorris = ClapTrap("jorris");
	FragTrap	teddy = FragTrap("teddy");

	teddy.highFivesGuys();
	jorris.beRepaired(5000000);
	teddy.attack("jorris");
	jorris.takeDamage(30);
	jorris.attack("teddy");
	teddy.takeDamage(0);
	teddy.beRepaired(0);
}
