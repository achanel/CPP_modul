#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->brain = new Brain();
    std::cout << "A Cat was created\n";
}

Cat::Cat(const Cat &copy)
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

Cat&  Cat::operator= (const Cat &other)
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
