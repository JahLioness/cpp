#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

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

    PresidentialPardonForm pardonForm("Alice");
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Bob");

    std::cout << pardonForm << std::endl;
    std::cout << shrubberyForm << std::endl;
    std::cout << robotomyForm << std::endl;

    std::cout << "=========== TEST SIGNATURE =========== " << std::endl;

    bob.signForm(pardonForm); // Should fail (grade too low)
    john.signForm(pardonForm); // Should succeed
    alice.signForm(shrubberyForm); // Should succeed
    bob.signForm(robotomyForm); // Should succeed

    std::cout << "=========== TEST EXECUTION =========== " << std::endl;

    alice.executeForm(shrubberyForm); // Should succeed (ASCII trees)
    john.executeForm(pardonForm); // Should succeed (pardon Alice)
    bob.executeForm(robotomyForm); // Should succeed or fail randomly (robotomy)

    std::cout << "=========== TEST INTERN =========== " << std::endl;

    Intern intern;

    // Test: Intern creates forms
    AForm *form1 = intern.makeForm("Shrubbery creation", "Garden");
    AForm *form2 = intern.makeForm("Robotomy request", "Bender");
    AForm *form3 = intern.makeForm("Presidential pardon", "Marvin");

    std::cout << *form1 << std::endl;
    std::cout << *form2 << std::endl;
    std::cout << *form3 << std::endl;

    // Test: Intern creates an invalid form
    try {
        AForm *invalidForm = intern.makeForm("invalid form", "Target");
        delete invalidForm; // Just in case it somehow succeeds
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test: Signing and executing forms created by the intern
    highRank.signForm(*form1); // Should succeed
    highRank.executeForm(*form1); // Should succeed (ASCII trees)

    bob.signForm(*form2); // Should succeed
    bob.executeForm(*form2); // Should succeed or fail randomly (robotomy)

    john.signForm(*form3); // Should succeed
    john.executeForm(*form3); // Should succeed (pardon Marvin)

    // Clean up
    delete form1;
    delete form2;
    delete form3;

    return 0;
}