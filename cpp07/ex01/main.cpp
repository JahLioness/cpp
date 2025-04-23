#include "iter.hpp"

int main(void) {
	int	array[5] = {9, 5, 3, 10, 56};
	::iter(array, 5, print<int>);
	std::cout << std::endl;

	std::string array2[5] = {"hello", "world", "salut", "moi"};
	::iter(array2, 5, print<std::string>);
	std::cout << std::endl;

	double array3[5] = {25.00, 456.365, 569.56, 598.365, 42.00};
	::iter(array3, 5, print<double>);
	std::cout << std::endl;

	const int	array4[5] = {9, 5, 3, 10, 56};
	::iter(array4, 5, print<const int>);
}
