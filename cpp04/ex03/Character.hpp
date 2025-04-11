#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class Character : virtual public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_dump[1024];

	public:
		Character(std::string const &name);
		Character(const Character &src);
		~Character(void);
		Character &operator=(const Character &character);
		std::string const &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
} ;

#endif