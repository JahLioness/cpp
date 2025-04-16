#include "Bureaucrat.hpp"

int main()
{

    std::cout << "===========TEST OVERLOAD OSTREAM=========== " << std::endl;
    
    // Bureaucrat    *defaultBureaucrat = new Bureaucrat();
    Bureaucrat    *paramBureaucrat = new Bureaucrat("John", 50);
    Bureaucrat    *copyBureaucrat = new Bureaucrat(*paramBureaucrat);
	Bureaucrat	*higherBureaucrat = new Bureaucrat("Patrick", 1);
    
    std::cout << *higherBureaucrat << std::endl;
    std::cout << *paramBureaucrat << std::endl;
    std::cout << *copyBureaucrat << std::endl;


    std::cout << "===========TEST INCREMENT/DECREMENT GRADE & EXCEPTION=========== " << std::endl;

    try
    {
        paramBureaucrat->upGrade();
        std::cout << *paramBureaucrat << std::endl;
        higherBureaucrat->upGrade(); // <--- exception catched
        std::cout << *higherBureaucrat << std::endl;  
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "===========TEST DEEP COPY=========== " << std::endl;
    
    *higherBureaucrat = *paramBureaucrat; // <----- deep copy

    std::cout << *higherBureaucrat << std::endl;
    std::cout << *paramBureaucrat << std::endl;

    higherBureaucrat->upGrade();
    std::cout << *higherBureaucrat << std::endl;
    std::cout << *paramBureaucrat << std::endl;

    // delete defaultBureaucrat;
    delete paramBureaucrat;
    delete copyBureaucrat;

    return (0);
}