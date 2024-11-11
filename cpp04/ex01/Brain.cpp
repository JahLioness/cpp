#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Now I can start thinking I have a brain" << std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "Brain just copied from another one" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "This is now a dead brain" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = brain._ideas[i];
	return (*this);
}

std::string Brain::getIdea(int N) const
{
	return (this->_ideas[N]);
}
