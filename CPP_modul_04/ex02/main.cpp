#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "-------------------------------------------\n";
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	std::cout << "-------------------------------------------\n";
	for(int i = 0; i < 100; i++)
		std::cout << j->getBrain()->getIdea()[i] << std::endl;
	std::cout << "-------------------------------------------\n";
	delete j;//should not create a leak
	delete i;
	std::cout << "-------------------------------------------\n";
	const Animal	*(Array[4]);
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			Array[i] = new Dog();
		else
			Array[i] = new Cat();
		std::cout << "-------------------------------------------\n";
	}
	for (int i = 0; i < 4; i++)
	{
		delete Array[i];
		std::cout << "-------------------------------------------\n";
	}
	system("leaks Abstract");
	return 0;
}