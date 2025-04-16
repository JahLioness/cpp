#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    std::cout << "===========TEST OVERLOAD OSTREAM=========== " << std::endl;

    Bureaucrat *defaultBureaucrat = new Bureaucrat("Patrick", 150);
    Bureaucrat *paramBureaucrat = new Bureaucrat("John", 50);
    Bureaucrat *copyBureaucrat = new Bureaucrat(*paramBureaucrat);

    std::cout << *defaultBureaucrat << std::endl;
    std::cout << *paramBureaucrat << std::endl;
    std::cout << *copyBureaucrat << std::endl;

    std::cout << "===========TEST INCREMENT/DECREMENT GRADE & EXCEPTION=========== " << std::endl;

    try {
        paramBureaucrat->upGrade();
        std::cout << *paramBureaucrat << std::endl;
        defaultBureaucrat->downGrade(); // <--- exception catched
        std::cout << *defaultBureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===========TEST DEEP COPY=========== " << std::endl;

    *defaultBureaucrat = *paramBureaucrat; // <----- deep copy

    std::cout << *defaultBureaucrat << std::endl;
    std::cout << *paramBureaucrat << std::endl;

    defaultBureaucrat->upGrade();
    std::cout << *defaultBureaucrat << std::endl;
    std::cout << *paramBureaucrat << std::endl;

    std::cout << "===========TEST FORM SIGNATURE=========== " << std::endl;

    try {
        Form formA("FormA", 40, 20); // Form requiring grade 40 to sign
        Form formB("FormB", 60, 30); // Form requiring grade 60 to sign

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        paramBureaucrat->signForm(formA); // Should throw GradeTooLowException
        paramBureaucrat->signForm(formB); // Should succeed
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===========TEST FORM EXCEPTIONS=========== " << std::endl;

    try {
        Form invalidFormHigh("InvalidFormHigh", 0, 20); // Invalid grade (too high)
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form invalidFormLow("InvalidFormLow", 151, 20); // Invalid grade (too low)
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    delete defaultBureaucrat;
    delete paramBureaucrat;
    delete copyBureaucrat;

    return 0;
}
