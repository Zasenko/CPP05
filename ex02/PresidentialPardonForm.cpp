#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("Presidential Form", 25, 5),
_target("defaultPresidentialTarget")
{
    std::cout << "PresidentialForm: Default constractor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("Presidential Form", 25, 5),
_target(target)
{
    std::cout << "PresidentialForm: Constractor called (target: " << target << ")" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialForm: Default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
AForm(copy.get_name(), copy.get_grade_to_sign(), copy.get_grade_to_execute()),
_target(copy._target)
{
    std::cout << "PresidentialForm: Copy constractor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    std::cout << "PresidentialForm: Assignment operator called" << std::endl;
    
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!get_is_signed()) throw FormNotSignedException();
    else if (executor.getGrade() > get_grade_to_execute()) throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
