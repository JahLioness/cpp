#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_book[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (this->_book[i])
			delete this->_book[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_book[i])
				delete this->_book[i];
			this->_book[i] = materiaSource._book[i];
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_book[i] == NULL)
			{
				this->_book[i] = m;
				break;
			}
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	if (type == "ice" || type == "cure")
	{
		for (int i = 3; i >= 0; i--)
		{
			if (this->_book[i] && this->_book[i]->getType() == type)
				return (this->_book[i]->clone());
		}
	}
	return (0);
}
