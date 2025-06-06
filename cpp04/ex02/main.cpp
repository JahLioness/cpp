#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		std::cout << animals[i]->getType() << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
}
