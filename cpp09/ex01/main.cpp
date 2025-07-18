#include "RPN.hpp"

void	ft_calcul(RPN *calc, std::string op)
{	
	double b = calc->list.top();
	calc->list.pop();
	double a = calc->list.top();
	calc->list.pop();
	if (op == "+")
		calc->list.push(a + b);
	else if (op == "-")
		calc->list.push(a - b);
	else if (op == "*")
		calc->list.push(a * b);
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: can't divide by 0");
		calc->list.push(a / b);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		RPN *calc = new RPN();
		std::istringstream iss(av[1]);
		std::string value;
		try
		{
			while (iss >> value) {
				if (std::isdigit(value[0]) && value.size() == 1)
					calc->list.push(std::strtod(value.c_str(), NULL));
				else if (value.size() == 1 && calc->list.size() > 1 && (value == "+" || value == "-" || value == "*" || value == "/"))
					ft_calcul(calc, value);
				else
					throw std::runtime_error("Error: " + std::string("\"") + std::string(value) + std::string("\"") + " is not a correct entry format");
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			delete calc;
			return (1);
		}
		if (calc->list.size() != 1)
			std::cerr << "Error: Couldn't complete the calcul" << std::endl;
		else
			std::cout << std::setprecision(2) << calc->list.top() << std::endl;
		delete calc;
	}
	else
		std::cerr << "Error: only one argument needed" << std::endl;
	return (0);
}