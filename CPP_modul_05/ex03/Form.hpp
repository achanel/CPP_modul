#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string	Name;
	bool	is_signed;
	unsigned int	gradeToSiqn;
	unsigned int	gradeToExecute;
public:
	Form();
	Form(std::string Name, unsigned int	gradeToSiqn, unsigned int gradeToExecute);
    Form(const Form &copy);
	Form &operator=(const Form &other);
	virtual ~Form();
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class FormUnsignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	std::string	getName() const;
	bool	isSigned() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExec() const;
	void	beSigned(Bureaucrat &bur);
	virtual void	action() const = 0;
	virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const Form &form); 

#endif