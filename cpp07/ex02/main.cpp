#include "Array.hpp"

int main() 
{
	int * a = new int();
	std::cout << *a << std::endl;
	std::cout << std::endl;

	Array< int > int_array(2);
	int_array[0] = 5;
	int_array[1] = 2;
	int_array.getArray();
	std::cout << std::endl;
	
	Array< float > float_array(3);
	float_array[0] = 5.56;
	float_array[1] = 2.96;
	float_array[2] = 42.00;
	float_array.getArray();
	std::cout << std::endl;
	
	Array< char > char_array(5);
	char_array[0] = 'h';
	char_array[1] = 'e';
	char_array[2] = 'l';
	char_array[3] = 'l';
	char_array[4] = '0';
	char_array.getArray();
	std::cout << std::endl;

	try
	{
		char_array[12] = 'w';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete a;
	return 0;
}