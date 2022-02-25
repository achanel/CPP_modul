#include "Form.hpp"

Form::Form(void)
{
	Name = "Unknown";
	gradeToSiqn = 1;
    gradeToExecute = 1;
	std::cout << "Default constructor called\n";
}

Form::Form(std::string name, unsigned int gradeToSiqn, unsigned int gradeToExecute)
{
	this->Name = name;
    if (gradeToSiqn < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSiqn > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
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

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too hight!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
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
    {
        is_signed = true;
        std::cout << bureaucrat.signForm(is_signed, Name) << std::endl;
    }
    else
    {
        is_signed = false;
        std::cout << bureaucrat.signForm(is_signed, Name);
        throw Bureaucrat::GradeTooLowException();
    }
}

Form::~Form(void)
{
	std::cout << "Destructor called\n";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    if (form.isSigned())
        out << "Form " << form.getName() << " with grade to sign " << form.getGradeToSign()
        << " and grade to execute " << form.getGradeToExec() << " is signed";
    else
        out << "Form " << form.getName() << " with grade to sign " << form.getGradeToSign()
        << " and grade to execute " << form.getGradeToExec() << " is not signed";
    return out;
}