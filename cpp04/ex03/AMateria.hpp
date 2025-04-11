#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &src);
		virtual ~AMateria(void);
		AMateria &operator=(const AMateria &aMatria);
		std::string const &getType(void) const;
		virtual AMateria *clone(void) = 0;
		virtual void use(ICharacter &target);
} ;

#endif