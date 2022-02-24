#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &copy)
{
    *this = copy;
}

Ice &Ice::operator=(const Ice &other)
{
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria *Ice::clone() const
{
    Ice *tmp = new Ice();
    *tmp = *this;
    return tmp;
}

Ice::~Ice()
{
}