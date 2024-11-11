#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{

}

Cure::Cure(const Cure &src) : AMateria(src)
{
	
}

Cure::~Cure(void)
{

}

Cure &Cure::operator=(const Cure &cure)
{
	AMateria::operator=(cure);
	return (*this);
}

std::string const &Cure::getType(void) const
{
	return (AMateria::getType());
}

Cure *Cure::clone(void)
{
	Cure *cure = new Cure(*this);
	return (cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
