#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;

	public:
		void complain(std::string level);
		Harl(void);
		~Harl(void);
} ;

#endif