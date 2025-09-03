#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default name"), _grade(150)
{
    std::cout << "Bureaucrat: Default constractor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << "Bureaucrat: Constractor called (name: " << name << ", grade: " << grade << ")" << std::endl;

    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    } else if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        _grade = grade;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: Default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()) {
    std::cout << "Bureaucrat: Copy constractor called" << std::endl;
    try {
        setGrade(copy.getGrade());
    }
    catch (std::exception &e) {
        throw e;
    }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    std::cout << "Bureaucrat: Assignment operator called" << std::endl;
    
    if (this != &src) {
        try {
            setGrade(src.getGrade());
        }
        catch (std::exception &e) {
            throw e;
        }
    }
    return *this;
}

const std::string Bureaucrat::getName(void) const
{
    return _name;
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

void Bureaucrat::incrementGrade(void)
{
    try {
        setGrade(_grade - 1);
    }
    catch (std::exception &e) {
        throw e;
    }
}

void Bureaucrat::decrementGrade(void)
{
    try {
        setGrade(_grade + 1);
    }
    catch (std::exception &e) {
        throw e;
    }
}

void Bureaucrat::setGrade(int grade)
{
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    } else if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        _grade = grade;
    }
}

void Bureaucrat::signForm(Form &form) const
{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.get_name() << std::endl;
    } catch (std::exception &e) {
        std::cout << getName() << " couldn’t sign " << form.get_name() << " because " << e.what() << std::endl;
    }
}



const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
    return os << src.getName() << ", bureaucrat grade " << src.getGrade();
}