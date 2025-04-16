#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		void	execute(Bureaucrat const &executor) const;
} ;

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &src);

#endif