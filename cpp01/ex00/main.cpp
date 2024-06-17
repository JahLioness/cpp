#include "Zombie.hpp"

int	main(void)
{
	Zombie	test;
	Zombie *first = newZombie("Stupid1");
	Zombie second("Stupid2");
	test.announce();
	first->announce();
	second.announce();
	randomChump("Stupid3");
	delete first;
}
