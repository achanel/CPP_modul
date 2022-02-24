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

void	Character::equip(AMateria* materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (array[i] == materia)
		{
			std::cout << name << " already has " << materia->getType() << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!array[i])
		{
			array[i] = materia;
			std::cout << name << " gas taken " << materia->getType() << std::endl;
			return ;
		}
	}
}

void	Character::unequip(int	index)
{
	if (array[index])
		array[index] = NULL;
}

void	Character::use(int index, ICharacter &target)
{
	if (array[index])
		array[index]->use(target);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		delete array[i];
}