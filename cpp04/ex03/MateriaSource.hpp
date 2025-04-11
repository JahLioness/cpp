#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : virtual public IMateriaSource
{
	private:
		AMateria *_book[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		~MateriaSource(void);
		MateriaSource &operator=(const MateriaSource &materiaSource);
		void learnMateria(AMateria *);
		AMateria *createMateria(std::string const &type);
} ;


#endif