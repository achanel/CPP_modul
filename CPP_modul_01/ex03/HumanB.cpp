#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->gun = NULL;
}

void	HumanB::setWeapon(Weapon &gun)
{
	this->gun = &gun;
}

void	HumanB::attack(void)
{
	if (this->gun == NULL)
		std::cout << this->name << " attacks with their hands" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->gun->getType() << std::endl;
}

HumanB::~HumanB(void)
{
}