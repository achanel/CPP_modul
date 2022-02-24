#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		array[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; ++i)
    	array[i] = copy.array[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this == &other)
        return *this;
	for (int i = 0; i < 4; ++i)
    	array[i] = other.array[i]->clone();
    return *this;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!array[i])
		{
			array[i] = materia;
			return ; 
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice" || type == "cure")
	{
		for (int i = 0; i < 4; ++i)
		{
			if (array[i] && array[i]->getType() == type)
				return (array[i]->clone());
		}
	}
	return 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete array[i];
}