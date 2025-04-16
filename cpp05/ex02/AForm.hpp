#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
  private:
	std::string const _name;
	std::string _target;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExec;
	AForm(void);

  public:
	AForm(std::string name, std::string target, int gradeToSign,
		int gradeToExec);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm(void);
	std::string getName(void) const;
	std::string getTarget(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExec(void) const;
	void beSigned(Bureaucrat signant);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormIsNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &src);

#endif