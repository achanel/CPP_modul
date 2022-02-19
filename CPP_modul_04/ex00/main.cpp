#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    std::cout << "-------------------------------------------\n";
    const Animal* j = new Dog();
    std::cout << "-------------------------------------------\n";
    const Animal* i = new Cat();
    std::cout << "-------------------------------------------\n";
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << "-------------------------------------------\n";
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}