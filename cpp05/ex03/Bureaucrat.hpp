#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int				_grade;
		Bureaucrat(void);
	
	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		~Bureaucrat(void);
		std::string	getName(void) const;
		int		getGrade(void) const;
		void	upGrade(void);
		void	downGrade(void);
		void	signForm(AForm &toSign);
		void	executeForm(AForm const &form) const;
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		} ;
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		} ;
} ;

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif