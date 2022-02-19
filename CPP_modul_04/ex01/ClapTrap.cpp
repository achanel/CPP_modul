#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    Name = "Unknown";
    Hit_points = 0;
    Energy = 0;
    Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    Hit_points = 10;
    Energy = 10;
    Attack_damage = 0;
    std::cout << "ClappTrapp " << this->Name << " was created\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
}

ClapTrap&  ClapTrap::operator= (const ClapTrap &other)
{
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy = other.Energy;
    this->Attack_damage = other.Attack_damage;

    return(*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (Energy <= 0)
    {
        std::cout << "No Energy to attack\n";
        return ;
    }
    this->Energy -= 1;
    std::cout << "ClapTrap " << this->Name << " attacks " << target;
    std::cout << " causing " << this->Attack_damage << " points of damage!\n";
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->Hit_points <= 0)
    {
        std::cout << this->Name << "already dead\n";
        return ;
    }
    this->Hit_points -= amount;
    std::cout << "ClapTrap " << this->Name << " takes damage causing " << amount << " points of damage!\n";
    if (this->Hit_points <= 0)
        std::cout << this->Name << " is dead\n";
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Hit_points <= 0)
    {
        std::cout << this->Name << "already dead\n";
        return ;
    }
    if (Energy <= 0)
    {
        std::cout << "No Energy to attack\n";
        return ;
    }

    this->Hit_points += amount;
    this->Energy -= 1;
    std::cout << "ClapTrap " << this->Name << " was repaired causing " << amount << " points of health!\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClappTrapp " << this->Name << " was destroyed\n";
}