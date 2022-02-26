#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# define COLOR "\033[0m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string	name;
	unsigned int			grade;
public:
	Bureaucrat();
	Bureaucrat(std::string Name, int Grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat&  operator= (const Bureaucrat &other);
	void	setGrade(int Grade);
	unsigned int	getGrade() const;
	std::string	getName() const;
	Bureaucrat &operator++();
	Bureaucrat &operator--();
	void	signForm(Form &form);
	void	executeForm(Form const &form);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	~Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif