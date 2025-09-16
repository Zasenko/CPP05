#include "AForm.hpp"

AForm::AForm():
_name("default name"),
_is_signed(false),
_grade_to_sign(150),
_grade_to_execute(150)
{
    std::cout << "AForm: Default constractor called" << std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute):
_name(name), 
_is_signed(false),
_grade_to_sign(grade_to_sign),
_grade_to_execute(grade_to_execute)
{
    std::cout << "AForm: Constractor called (name: " << name << ", grade to sign: " << grade_to_sign << ", grade to execute: " << grade_to_execute << ")" << std::endl;
    
    if (grade_to_sign > 150 || grade_to_execute > 150) {
        throw Bureaucrat::GradeTooLowException();
    } else if (grade_to_sign < 1 || grade_to_execute < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
}

AForm::~AForm()
{
    std::cout << "AForm: Default destructor called" << std::endl;
}

AForm::AForm(const AForm &copy):
_name(copy.get_name()),
_is_signed(copy.get_is_signed()),
_grade_to_sign(copy.get_grade_to_sign()),
_grade_to_execute(copy.get_grade_to_execute())
{
    std::cout << "AForm: Copy constractor called" << std::endl;
}

AForm &AForm::operator=(const AForm &src)
{
    std::cout << "AForm: Assignment operator called" << std::endl;

    if (this != &src) {
        _is_signed = src.get_is_signed();
    }
    return *this;
}

const std::string AForm::get_name() const
{
    return _name;
}

bool AForm::get_is_signed() const
{
    return _is_signed;
}

int AForm::get_grade_to_sign() const
{
    return _grade_to_sign;
}

int AForm::get_grade_to_execute() const
{
    return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (_is_signed) {
        std::cout << "Form " << _name << " is already signed." << std::endl;
    } else {
        if (b.getGrade() <= get_grade_to_sign()) {
            _is_signed= true;
        } else if (b.getGrade() > get_grade_to_sign()) {
            throw AForm::GradeTooLowException();
        }
    }
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &src)
{
    std::string is_signed_text = src.get_is_signed() ? " is signed. " : " is not signed. ";
    return os << "AForm " << src.get_name() << is_signed_text << "Grade to sign: " << src.get_grade_to_sign() << ", grade to execute: " << src.get_grade_to_execute();
}
