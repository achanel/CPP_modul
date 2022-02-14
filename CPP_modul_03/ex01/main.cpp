#include "ScavTrap.hpp"

int     main(void)
{
    ClapTrap    Boris("Boris");
    std::cout << "-------------------------------------------\n";
    ClapTrap    Denis("Denis");
    std::cout << "-------------------------------------------\n";
    ScavTrap    Fanis("Fanis");
    std::cout << "-------------------------------------------\n";
    Boris.attack("Denis");
    Denis.takeDamage(0);
    Denis.beRepaired(2);
    std::cout << "-------------------------------------------\n";
    Denis.attack("Boris");
    Boris.takeDamage(0);
    Boris.beRepaired(1);
    std::cout << "-------------------------------------------\n";
    Fanis.attack("Denis");
    Fanis.takeDamage(45);
    Fanis.beRepaired(10);
    Fanis.guardGate();
    return 0;
}