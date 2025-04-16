#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExec;
	Form(void);

  public:
	Form(std::string name, int gradeToSign, int gradeToExec);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form(void);
	std::string getName(void) const;
	bool 		getIsSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExec(void) const;
	void		beSigned(Bureaucrat signant);
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif