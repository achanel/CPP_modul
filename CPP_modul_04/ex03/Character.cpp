#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; ++i)
		array[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; ++i)
		array[i] = NULL;
}

Character::Character(const Character &copy)
{
	name = copy.name;
	for (int i = 0; i < 4; ++i)
    	array[i] = copy.array[i]->clone();
}

Character &Character::operator=(const Character &other)
{
    if (this == &other)
        return *this;
	for (int i = 0; i < 4; ++i)
	{
		if (this->array[i])
			delete this->array[i];
		if (other.array[i])
    		this->array[i] = other.array[i]->clone();
	}
    return *this;
}

const std::string &Character::getName() const
{
	return name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (array[i] == m)
		{
			std::cout << name << " already has " << m->getType() << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!array[i])
		{
			array[i] = m;
			std::cout << name << " has taken " << m->getType() << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (array[idx])
		array[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (array[idx])
		array[idx]->use(target);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete array[i];
}