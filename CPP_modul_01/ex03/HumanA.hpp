#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
    Weapon      &gun;
public:
	HumanA(std::string name, Weapon &gun);
	void    attack(void);
	~HumanA();
};


#endif