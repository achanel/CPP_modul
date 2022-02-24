#include "AMateria.hpp"

AMateria::AMateria()
{
    this->type = "Unknown";
}

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

std::string const &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses some materia at " << target.getName() << " *\n";
}

AMateria::~AMateria()
{
    this->type.clear();
}