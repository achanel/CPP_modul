#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &copy);
        Ice&  operator= (const Ice &other);
        virtual void use(ICharacter& target);
        virtual AMateria* clone() const;
        ~Ice();
};

#endif