#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &src);
		virtual ~Animal(void);
		Animal &operator=(const Animal &animal);

		virtual void	makeSound() const;
		std::string getType(void) const;
} ;

#endif