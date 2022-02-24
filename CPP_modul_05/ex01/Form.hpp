#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool	isSigned(int grade);
	int	gradeToSiqn() const;
	int	gradeToExecute() const;
public:
	Form();
	Form(std::string Name);
    Form(const Form &copy);
	std::string	getName() const;
	void	beSigned(Bureaucrat bur);
	~Form();
};

std::ostream &operator<<(std::ostream &out, const Form &b); 

#endif