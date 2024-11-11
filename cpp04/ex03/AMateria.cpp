#include "AMateria.hpp"

AMateria::AMateria(void)
{

}

AMateria::AMateria(std::string const &type) : type(type)
{
	
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria::~AMateria(void)
{

}

AMateria &AMateria::operator=(const AMateria &aMateria)
{
	if (this != &aMateria)
		this->type = aMateria.type;
	return (*this);
}

std::string const &AMateria::getType(void) const
{
	return (this->type);
}

void AMateria::use(ICharacter &target)
{

}
