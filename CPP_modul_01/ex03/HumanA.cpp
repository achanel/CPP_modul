#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &gun) : gun(gun)
{
    this->name = name;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->gun.getType() << std::endl;
}

HumanA::~HumanA(void)
{
}