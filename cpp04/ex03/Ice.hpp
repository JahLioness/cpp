#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : virtual public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &src);
		~Ice(void);
		Ice &operator=(const Ice &ice);
		std::string const &getType(void) const;
		Ice *clone(void);
		void use(ICharacter &target);
} ;

#endif