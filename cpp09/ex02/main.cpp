#include "PmergeMe.hpp"

bool ft_check_entries(char **av, int ac)
{
	std::string temp;
	for (int i = 1; i < ac; i++)
	{
		temp = av[i];
		if (std::atol(av[i]) > INT_MAX || std::atol(av[i]) < 0)
			return (0);
		for (unsigned long j = 0; j < temp.size(); j++)
		{
			if (!isdigit(av[i][j]))
				return (0);
		}
	}
	return (1);
}

int main(int ac, char **av) {
	if (!ft_check_entries(av, ac))
	{
		std::cerr << "Invalid entries, please enter positive integers only" << std::endl;
		return (1);
	}
	std::vector<unsigned int> vec;
	std::deque<unsigned int> deq;
	for (int i = 1; i < ac; i++)
	{
		vec.push_back(std::atoi(av[i]));
		deq.push_back(std::atoi(av[i]));
	}
	if (vec.size() < 2)
	{
		std::cerr << "Invalid entries, please enter at least 2 positive integers" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe(vec, deq);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}