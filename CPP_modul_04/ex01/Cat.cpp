#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->brain = new Brain();
    std::cout << "A Cat was created\n";
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
}

Cat&  Cat::operator= (const Cat &other)
{
    this->type = other.type;
    return (*this);
}

const   std::string &Cat::getType(void) const
{
    return (type);
}

void    Cat::makeSound(void) const
{
    std::cout << type << " says miau\n";
}

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}

Cat::~Cat()
{
	delete this->brain;
    std::cout << "Cat was destroyed\n";
}