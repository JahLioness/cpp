#include "Zombie.hpp"

Zombie::Zombie(void): name("Stupid")
{
	std::cout << "Zombie " + this->name + " is born" << std::endl;
}

Zombie::Zombie(std::string name): name(name)
{
	std::cout << "Zombie " + this->name + " is born" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " + this->name + " has been destroyed" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}