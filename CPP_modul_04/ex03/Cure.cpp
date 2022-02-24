#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &copy)
{
    *this = copy;
}

Cure &Cure::operator=(const Cure &other)
{
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria *Cure::clone() const
{
    Cure *tmp = new Cure();
    *tmp = *this;
    return tmp;
}

Cure::~Cure()
{
}