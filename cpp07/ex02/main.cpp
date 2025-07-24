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

// #include <iostream>
// #include "Array.hpp"
// #include <cstdlib>
// #include <ctime>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
