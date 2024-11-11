#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
	private:
		Brain *_brain;

	protected:
		std::string _type;

	public:
		Cat(void);
		Cat(const Cat &src);
		~Cat(void);
		Cat &operator=(const Cat &cat);

		void	makeSound(void) const;
		std::string getType(void) const;
} ;

#endif