#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->Name = "Unknown";
    this->Hit_points = 0;
    this->Energy = 0;
    this->Attack_damage = 0;
}

ScavTrap::ScavTrap(std::string name)
{
    this->Name = name;
    this->Hit_points = 100;
    this->Energy = 50;
    this->Attack_damage = 20;
    std::cout << "ScavTrapp " << this->Name << " was created\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    *this = copy;
}

ScavTrap&  ScavTrap::operator= (const ScavTrap &other)
{
    if (&other == this)
        return (*this);
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy = other.Energy;
    this->Attack_damage = other.Attack_damage;

    return(*this);
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->Name << " was destroyed\n";
}