#include <iostream>
#include <fstream>

void	ft_replace(std::fstream& infile, std::string filename, std::string to_replace, std::string replacement)
{
	std::string ifilename = filename;
	std::string ofilename = ifilename.append(".replace");
	const char *test = ofilename.c_str();
	int		pos = 0;
	std::string line;
	std::fstream outfile;

	outfile.open(test, std::fstream::out);
	while (std::getline(infile, line))
	{
		while (pos >= 0)
		{
			pos = line.find(to_replace, pos);
			if (pos >= 0)
			{
				line.erase(pos, to_replace.length());
				line.insert(pos, replacement);
				pos += replacement.length();
			}
		}
		if (outfile.is_open())
			outfile << line << std::endl;
		pos = 0;
	}
	outfile.close();
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::fstream infile;
		std::string	to_replace = av[2];
		if (to_replace.empty())
		{
			std::cout << "The string to replace cannot be emtpy" << std::endl;
			return (1);
		}
		infile.open(av[1], std::fstream::in);
		if (infile.is_open())
			ft_replace(infile, av[1], av[2], av[3]);
		else
			std::cout << "Can't open file " << av[1] << std::endl;
		infile.close();
	}
	else
		std::cout << "Wrong number of arguments passed" << std::endl;
	return (0);
}
