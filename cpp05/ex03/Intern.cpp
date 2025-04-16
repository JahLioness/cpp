#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {

}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

const char *Intern::FormDoesntExistException::what() const throw() {
	return ("You entered an invalid form name, please select between Robotomy request, Presidential pardon or Shrubbery creation\n");
}

AForm *Intern::makePresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	AForm *(Intern::*functptr[3])(std::string target) = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	std::string tab[3] = {"Robotomy request", "Presidential pardon", "Shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == tab[i])
			return (this->*functptr[i])(formTarget);
	}
	throw Intern::FormDoesntExistException();
}
