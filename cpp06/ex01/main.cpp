#include "Serializer.hpp"

int main(void) {
	Data *ptr = new (Data);
	Data *ptr1;
	ptr->name = "hello";
	ptr->value = 42;

	std::cout << "before serialization: " << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << "value: " << ptr->value << std::endl; 
	std::cout << std::endl;

	uintptr_t test =  Serializer::serialize(ptr);
	ptr1 = Serializer::deserialize(test);

	std::cout << "after serialization: " << std::endl;
	std::cout << "uintptr_t value: " << test << std::endl;
	std::cout << "name: " << ptr1->name << std::endl;
	std::cout << "value: " << ptr1->value << std::endl;
	std::cout << std::endl;

	ptr->name = "hello world";
	ptr->value = 21;
	std::cout << "after serialization and change of original values: " << std::endl;
	std::cout << "uintptr_t value: " << test << std::endl;
	std::cout << "name: " << ptr1->name << std::endl;
	std::cout << "value: " << ptr1->value << std::endl;
	delete ptr;
	return (0);
}