#include "ClapTrap.hpp"

int     main(void)
{
    ClapTrap    Boris("Boris");
    ClapTrap    Denis("Denis");

    Boris.attack("Denis");
    Denis.takeDamage(0);
    Denis.beRepaired(2);

    Denis.attack("Boris");
    Boris.takeDamage(0);
    Boris.beRepaired(1);
    return 0;
}