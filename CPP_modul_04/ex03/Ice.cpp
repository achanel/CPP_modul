#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
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
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria *Ice::clone() const
{
    Ice    *tmp = new Ice();
    *tmp = *this;
    return tmp;
}

Ice::~Ice()
{
}