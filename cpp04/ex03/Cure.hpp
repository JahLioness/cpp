#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: virtual public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &src);
		~Cure(void);
		Cure &operator=(const Cure &cure);
		std::string const &getType(void) const;
		Cure *clone(void);
		void use(ICharacter &target);
} ;

#endif