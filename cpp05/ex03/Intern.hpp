#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern &operator=(const Intern &src);
		AForm *makePresidential(std::string target);
		AForm *makeRobotomy(std::string target);
		AForm *makeShrubbery(std::string target);
		AForm *makeForm(std::string formName, std::string formTarget);
		class FormDoesntExistException : public std::exception {
			virtual const char *what() const throw();
		};
} ;

#endif