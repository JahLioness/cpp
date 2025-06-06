#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *_brain;

	protected:
		std::string _type;

	public:
		Dog(void);
		Dog(const Dog &src);
		~Dog(void);
		Dog &operator=(const Dog &dog);

		void	makeSound(void) const;
		std::string getType(void) const;
} ;

#endif