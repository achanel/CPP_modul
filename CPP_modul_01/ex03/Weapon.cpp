#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
    this->weapon = weapon;
}

const std::string    &Weapon::getType(void)
{
    const std::string   &weaponREF = this->weapon;
    return(weaponREF);
}

void    Weapon::setType(std::string str)
{
    this->weapon = str;
}

Weapon::~Weapon(void)
{
}