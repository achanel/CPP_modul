#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"


class HumanB
{
private:
	std::string	name;
    Weapon      *gun;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon &gun);
    void    attack(void);
	~HumanB();
};


#endif