#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	AMateria	*array[4];
	std::string	name;
public:
		Character();
		Character(std::string name);
        Character(const Character &copy);
        Character&  operator= (const Character &other);
		const std::string &getName() const;
		void	equip(AMateria* m);
		void	unequip(int	idx);
		void	use(int idx, ICharacter &target);
        ~Character();
};

#endif