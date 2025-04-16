#include "PresidentialPardonForm.hpp"
#include <sstream>
#include <cstdlib>
#include <ctime>

static std::string generate_random(std::string name) {
	std::ostringstream s;
	std::srand(time(NULL));
	int	rando = std::rand();
	s << name + " " << rando;
	std::string query(s.str());
	return (query);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm::AForm(generate_random("PresidentialPardonForm"), target, 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	if (!this->getIsSigned())
		throw AForm::FormIsNotSignedException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zalphod Beeblerox." << std::endl;	
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &src)
{
	o << "Form name: " << src.getName() << ", this form is required by " << src.getTarget() << ", the required grade to sign this form: " << src.getGradeToSign() << ", the required grade to execute this form: " << src.getGradeToExec() << (src.getIsSigned() ? "this form is signed" : " this form is not signed") << std::endl;
	return (o);
}
