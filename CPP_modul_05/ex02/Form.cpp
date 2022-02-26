#include "Form.hpp"

Form::Form(void)
{
	Name = "Unknown";
	gradeToSiqn = 150;
    gradeToExecute = 150;
	std::cout << "Default constructor called\n";
}

Form::Form(std::string name, unsigned int gradeToSiqn, unsigned int gradeToExecute)
{
	this->Name = name;
    if (gradeToSiqn < 1 || gradeToExecute < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeToSiqn > 150 || gradeToExecute > 150)
        throw Bureaucrat::GradeTooLowException();
	this->gradeToSiqn = gradeToSiqn;
    this->gradeToExecute = gradeToExecute;
	std::cout << "Constructor name = " << name << " with grade to sign = " << gradeToSiqn;
    std::cout << " and grade to execute = " << gradeToExecute << " called\n";
}

Form::Form(const Form &copy)
{
	this->Name = copy.Name;
	this->gradeToSiqn = copy.gradeToSiqn;
    this->gradeToExecute = copy.gradeToExecute;
	std::cout << "Copy constructor called\n";
}

Form&  Form::operator= (const Form &other)
{
    if (this == &other)
        return *this;
	this->gradeToSiqn = other.getGradeToSign();
    this->gradeToExecute = other.getGradeToExec();
	return *this;
	std::cout << "Assignation operator called\n";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too hight!";
}

const char *Form::FormUnsignedException::what() const throw()
{
	return "Form is unsigned!";
}

std::string Form::getName(void) const
{
    return Name;
}

bool    Form::isSigned(void) const
{
    return is_signed;
}

unsigned int    Form::getGradeToSign(void) const
{
    return gradeToSiqn;
}

unsigned int    Form::getGradeToExec(void) const
{
    return gradeToExecute;
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() < gradeToSiqn)
        is_signed = true;
    else
    {
        is_signed = false;
        throw Bureaucrat::GradeTooLowException();
    }
}

void	Form::execute(Bureaucrat const & executor) const
{
	if (this->isSigned())
	{
		if (executor.getGrade() <= gradeToExecute)
			this->action();
		else
			throw Bureaucrat::GradeTooLowException();
	}
	else
		throw FormUnsignedException();
	std::cout << GREEN << executor.getName() << " executes form " << this->Name << std::endl << COLOR;
}

Form::~Form(void)
{
	std::cout << "Destructor Form called\n";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    if (form.isSigned())
        out << "Form " << form.getName() << " with grade to sign " << form.getGradeToSign()
        << " and grade to execute " << form.getGradeToExec() << " is signed\n";
    else
        out << "Form " << form.getName() << " with grade to sign " << form.getGradeToSign()
        << " and grade to execute " << form.getGradeToExec() << " is not signed\n";
    return out;
}
