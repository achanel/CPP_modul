#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    // const   std::string &getName(void) const;
    // int     getHit_points(void) const;
    // int     getEnergy(void) const;
    // int     getAttack_damage(void) const;
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap&  operator= (const DiamondTrap &other);
    using   ScavTrap::attack;
    void    whoAmI();
    ~DiamondTrap();
};


#endif