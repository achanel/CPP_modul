#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->Name = "Unknown";
    this->Hit_points = 0;
    this->Energy = 0;
    this->Attack_damage = 0;
    std::cout << "FragTrapp " << this->Name << " was created\n";
}

FragTrap::FragTrap(std::string name)
{
    this->Name = name;
    this->Hit_points = 100;
    this->Energy = 50;
    this->Attack_damage = 20;
    std::cout << "FragTrapp " << this->Name << " was created\n";
}

FragTrap::FragTrap(const FragTrap &copy)
{
    *this = copy;
}

FragTrap&  FragTrap::operator= (const FragTrap &other)
{
    if (&other == this)
        return (*this);
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy = other.Energy;
    this->Attack_damage = other.Attack_damage;

    return(*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap" << this->Name << " hive Five!\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->Name << " was destroyed\n";
}