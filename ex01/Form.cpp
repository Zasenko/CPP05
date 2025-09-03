#include "Form.hpp"

Form::Form():
_name(),
_is_signed(false),
_grade_to_sign(150),
_grade_to_execute(150)
{
    std::cout << "Form: Default constractor called" << std::endl;

}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute):
_name(name), 
_is_signed(false),
_grade_to_sign(grade_to_sign),
_grade_to_execute(grade_to_execute)
{
    std::cout << "Form: Constractor called (name: " << name << ", grade to sign: " << grade_to_sign << ", grade to execute: " << grade_to_execute << ")" << std::endl;
}

Form::~Form()
{
    std::cout << "Form: Default destructor called" << std::endl;
}

Form::Form(const Form &copy):
_name(copy.get_name()),
_is_signed(copy.get_is_signed()),
_grade_to_sign(copy.get_grade_to_sign()),
_grade_to_execute(copy.get_grade_to_execute())
{
    std::cout << "Form: Copy constractor called" << std::endl;
}

Form &Form::operator=(const Form &src)
{
    std::cout << "Form: Assignment operator called" << std::endl;

    if (this != &src) {
        _is_signed = src.get_is_signed();
    }
    return *this;
}

const std::string Form::get_name() const
{
    return _name;
}

bool Form::get_is_signed() const
{
    return _is_signed;
}

const int Form::get_grade_to_sign() const
{
    return _grade_to_sign;
}

const int Form::get_grade_to_execute() const
{
    return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= get_grade_to_sign()) {
        _is_signed = true;
    } else if (b.getGrade() > get_grade_to_sign()) {
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
    std::string is_signed_text = src.get_is_signed() ? " is signed. " : " is not signed. ";
    return os << "Form " << src.get_name() << is_signed_text << "Grade to sign: " << src.get_grade_to_sign() << ", grade to execute: " << src.get_grade_to_execute();
}
