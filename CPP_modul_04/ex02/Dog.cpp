#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->brain = new Brain();
    std::cout << "A Dog was created\n";
}

Dog::Dog(const Dog &copy)
{
    type = copy.getType();
	if (copy.getBrain())
	{
		brain = new Brain(*(copy.getBrain()));
		std::cout << "Brain was copied\n";
	}
	else
		std::cout << "Can't copy brain\n";
}

Dog&  Dog::operator= (const Dog &other)
{
	if (this == &other)
		return (*this);
	if (this->brain)
		delete this->brain;
	this->brain = new Brain();
	this->brain = other.brain;
    this->type = other.type;
    return (*this);
}

const   std::string &Dog::getType(void) const
{
    return (type);
}

void    Dog::makeSound(void) const
{
    std::cout << type << " says gav\n";
}

Brain	*Dog::getBrain(void) const
{
	return (this->brain);
}

Dog::~Dog()
{
	delete this->brain;
    std::cout << "Dog was destroyed\n";
}
