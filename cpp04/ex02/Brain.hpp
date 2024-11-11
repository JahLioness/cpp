#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain &src);
		~Brain(void);

		Brain &operator=(const Brain &brain);
		std::string getIdea(int N) const;
} ;

#endif