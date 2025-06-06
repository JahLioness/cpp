#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal(void);

		WrongAnimal &operator=(const WrongAnimal &wrongAnimal);
		void	makeSound(void) const;
		std::string getType(void) const;
} ;

#endif