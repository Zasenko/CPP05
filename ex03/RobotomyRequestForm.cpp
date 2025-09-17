#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
AForm("Robotomy Form", 72, 45),
_target("defaultRobotomyTarget")
{
    std::cout << "RobotomyForm: Default constractor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("Robotomy Form", 72, 45),
_target(target)
{
    std::cout << "RobotomyForm: Constractor called (target: " << target << ")" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyForm: Default destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
AForm(copy.get_name(), copy.get_grade_to_sign(), copy.get_grade_to_execute()),
_target(copy._target)
{
    std::cout << "RobotomyForm: Copy constractor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    std::cout << "RobotomyForm: Assignment operator called" << std::endl;
    
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!get_is_signed()) throw FormNotSignedException();
    else if (executor.getGrade() > get_grade_to_execute()) throw GradeTooLowException();

    std::cout << "some drilling noises"<< std::endl;

    std::srand(time(0));
    if (rand() % 2) {
        std::cout << "RobotomyForm: " << _target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "RobotomyForm (" << _target << "): the robotomy failed" << std::endl;
    }
}
