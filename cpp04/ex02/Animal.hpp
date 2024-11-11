#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		virtual ~Animal(void) = 0;
		// Animal(void);
		// Animal(std::string type);
		// Animal(const Animal &src);
		// Animal &operator=(const Animal &animal);

		virtual void	makeSound() const = 0;
		virtual std::string getType(void) const = 0;
} ;

#endif