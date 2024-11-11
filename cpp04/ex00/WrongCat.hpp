#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &src);
		~WrongCat(void);

		WrongCat &operator=(const WrongCat &wrongCat);
		void	makeSound(void) const;
		std::string getType(void) const;
} ;

#endif