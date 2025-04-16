#include "AForm.hpp"

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExec): _name(name), _target(target), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	*this = src;
}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src)
	{
		_target = src._target;
		_isSigned = src._isSigned;
	}
	return (*this);
}

AForm::~AForm() {

}

std::string	AForm::getName(void) const {
	return (_name);
}

std::string AForm::getTarget(void) const {
	return (_target);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}

int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

int AForm::getGradeToExec(void) const {
	return (_gradeToExec);
}

void	AForm::beSigned(Bureaucrat signant) {
	if (_gradeToSign < signant.getGrade())
		throw AForm::GradeTooLowException();
	else
		_isSigned = 1;
}

const char*AForm::GradeTooHighException::what() const throw() {
	return ("grade is too high to interract with the form\n");
}

const char*AForm::GradeTooLowException::what() const throw() {
	return ("grade is too low to interract with the form.\n");
}

const char*AForm::FormIsNotSignedException::what() const throw() {
	return ("form is not signed yet, impossible to execute.\n");
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << "Form name: " << src.getName() << ", required grade to sign this form: " << src.getGradeToSign() << ", required grade to execute this form: " << src.getGradeToExec() << (src.getIsSigned() ? "this form is signed" : " this form is not signed") << std::endl;
	return (o);
}

