#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    std::cout << "=========== TEST BUREAUCRAT CREATION =========== " << std::endl;
    Bureaucrat john("John", 5);
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 150);
    Bureaucrat highRank("HighRank", 1);
    Bureaucrat lowRank("LowRank", 150);

    std::cout << john << std::endl;
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;
    std::cout << highRank << std::endl;
    std::cout << lowRank << std::endl;

    std::cout << "=========== TEST FORM CREATION =========== " << std::endl;
    AForm *pardonForm = new PresidentialPardonForm("Alice");
    AForm *shrubberyForm = new ShrubberyCreationForm("Home");
    AForm *robotomyForm = new RobotomyRequestForm("Bob");

    std::cout << *pardonForm << std::endl;
    std::cout << *shrubberyForm << std::endl;
    std::cout << *robotomyForm << std::endl;

    std::cout << "=========== TEST SIGNATURE =========== " << std::endl;
    bob.signForm(*pardonForm); // Should fail (grade too low)
    john.signForm(*pardonForm); // Should succeed
    alice.signForm(*shrubberyForm); // Should succeed
    bob.signForm(*robotomyForm); // Should succeed

    std::cout << "=========== TEST EXECUTION =========== " << std::endl;
    alice.executeForm(*shrubberyForm); // Should succeed (ASCII trees)
    john.executeForm(*pardonForm); // Should succeed (pardon Alice)
    bob.executeForm(*robotomyForm); // Should succeed or fail randomly (robotomy)

    std::cout << "=========== TEST EXCEPTIONS =========== " << std::endl;

    // Test: Execution of an unsigned form
    PresidentialPardonForm *unsignedForm = new PresidentialPardonForm("Unsigned");
    john.executeForm(*unsignedForm); // Should throw FormNotSignedException

    std::cout << *unsignedForm << std::endl;


    PresidentialPardonForm test = *unsignedForm;




    std::cout << test << std::endl;

    // Test: Execution by a bureaucrat with insufficient grade
    lowRank.executeForm(*pardonForm); // Should throw GradeTooLowException

    // Test: Signing and executing a form with a high-rank bureaucrat
    ShrubberyCreationForm validForm("Garden");
    highRank.signForm(validForm); // Should succeed
    highRank.executeForm(validForm); // Should succeed

    // Clean up
    delete pardonForm;
    delete shrubberyForm;
    delete robotomyForm;
    delete unsignedForm;

    return 0;
}