#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
protected:
	AMateria	*array[4];
public:
	    MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource&  operator= (const MateriaSource &other);
		void	learnMateria(AMateria* materia);
		AMateria	*createMateria(std::string const & type);
        ~MateriaSource();
};

#endif