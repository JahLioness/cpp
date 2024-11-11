#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{

}

Ice::Ice(const Ice &src) : AMateria(src)
{

}

Ice::~Ice(void)
{

}

Ice &Ice::operator=(const Ice &ice)
{
	AMateria::operator=(ice);
	return (*this);
}

std::string const &Ice::getType(void) const
{
	return (AMateria::getType());
}

Ice *Ice::clone(void)
{
	Ice *ice = new Ice(*this);
	return (ice);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
