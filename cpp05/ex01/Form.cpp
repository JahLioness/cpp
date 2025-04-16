#include "Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
}

Form &Form::operator=(const Form &src) {
	if (this != &src)
		_isSigned = src._isSigned;
	return (*this);
}

Form::~Form() {

}

std::string	Form::getName(void) const {
	return (_name);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

int Form::getGradeToExec(void) const {
	return (_gradeToExec);
}

void	Form::beSigned(Bureaucrat signant) {
	if (_gradeToSign < signant.getGrade())
		throw Form::GradeTooLowException();
	else
		_isSigned = 1;
}

const char*Form::GradeTooHighException::what() const throw() {
	return ("grade is too high to interract with the form\n");
}

const char*Form::GradeTooLowException::what() const throw() {
	return ("grade is too low to interract with the form.\n");
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << "Form name: " << src.getName() << ", required grade to sign this form: " << src.getGradeToSign() << ", required grade to execute this form: " << src.getGradeToExec() << (src.getIsSigned() ? "this form is signed" : " this form is not signed") << std::endl;
	return (o);
}

