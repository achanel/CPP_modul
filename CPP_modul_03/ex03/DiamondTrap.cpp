#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
    Name = "Unknown";
    ClapTrap::Name = Name + "_clap_name";
    Hit_points = 0;
    Energy = 0;
    Attack_damage = 0;
    std::cout << "DiamondTrapp " << this->Name << " was created\n";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
    this->Name = name;
    ClapTrap::Name = Name + "_clap_name";
    this->Hit_points = 100;
    this->Energy = 50;
    this->Attack_damage = 30;
    std::cout << "DiamondTrapp " << this->Name << " was created\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
{
    *this = copy;
}

DiamondTrap&  DiamondTrap::operator= (const DiamondTrap &other)
{
    if (&other == this)
        return (*this);
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy = other.Energy;
    this->Attack_damage = other.Attack_damage;

    return(*this);
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "I am " << this->Name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->Name << " was destroyed\n";
}