#include "DiamondTrap.hpp"

int     main(void)
{
    ClapTrap    Boris("Boris");
    ClapTrap    Denis("Denis");
    std::cout << "-------------------------------------------\n";
    ScavTrap    Fanis("Fanis");
    ScavTrap    Ilgis("Ilgis");
    std::cout << "-------------------------------------------\n";
    FragTrap    Aramis("Aramis");
    FragTrap    Patris("Patris");
    std::cout << "-------------------------------------------\n";
    DiamondTrap Javis("Javis");
    DiamondTrap Otjavis("Otjavis");
    std::cout << "-------------------------------------------\n";
    Boris.attack("Denis");
    Boris.takeDamage(0);
    Boris.beRepaired(2);
    std::cout << "-------------------------------------------\n";
    Denis.attack("Boris");
    Denis.takeDamage(0);
    Denis.beRepaired(1);
    std::cout << "-------------------------------------------\n";
    Fanis.attack("Denis");
    Fanis.takeDamage(45);
    Fanis.beRepaired(10);
    Fanis.guardGate();
    std::cout << "-------------------------------------------\n";
    Aramis.attack("Fanis");
    Aramis.takeDamage(20);
    Aramis.beRepaired(10);
    Aramis.highFivesGuys();
    Patris.highFivesGuys();
    std::cout << "-------------------------------------------\n";
    Aramis.attack("Fanis");
    Aramis.takeDamage(20);
    Aramis.beRepaired(10);
    Aramis.highFivesGuys();
    Patris.highFivesGuys();
    std::cout << "-------------------------------------------\n";
    Javis.attack("Aramis");
    Javis.takeDamage(32);
    Javis.beRepaired(14);
    Javis.whoAmI();
    Otjavis.highFivesGuys();
    Otjavis.guardGate();
    std::cout << "-------------------------------------------\n";
    return 0;
}