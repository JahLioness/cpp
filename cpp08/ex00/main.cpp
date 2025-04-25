#include "easyfind.hpp"
#include <vector>
#include <list>

template <typename T> void test(T array, int val){
	typename T::iterator index = ::easyfind(array, val);
	std::cout << "value find at index : " << std::distance(array.begin(), index) << std::endl;
}

int main(void){
	std::vector<int> cont;
	cont.push_back(5);
	cont.push_back(98);
	cont.push_back(11);
	cont.push_back(16);
	cont.push_back(65);
	cont.push_back(28);
	cont.push_back(42);
	::test(cont, 42);
	std::cout << std::endl;

	int	array[] = {15, 26, 75, 42, 85, 42, 65, 9};
	std::list<int> intArray(array, array + 9);
	::test(intArray, 42);
	std::cout << std::endl;
	
	try
	{
		::test(intArray, 24);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}