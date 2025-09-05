#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("Shrubbery Form", 145, 137),
_target("defaultShrubberyTarget")
{
    std::cout << "ShrubberyForm: Default constractor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("Shrubbery Form", 145, 137),
_target(target)
{
    std::cout << "ShrubberyForm: Constractor called (target: " << target << ")" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyForm: Default destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
AForm(copy.get_name(), copy.get_grade_to_sign(), copy.get_grade_to_execute()),
_target(copy._target)
{
    std::cout << "ShrubberyForm: Copy constractor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    std::cout << "ShrubberyForm: Assignment operator called" << std::endl;
    
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!get_is_signed()) throw FormNotSignedException();
    else if (executor.getGrade() > get_grade_to_execute()) throw GradeTooLowException();

    std::ofstream new_file;
    std::string file_name = _target + "_shrubbery";
    new_file.open(file_name);
    if (!new_file.is_open()) throw FileNotOpenOrCreatedException();

    new_file
    << "   0000" << std::endl
    << "  000000" << std::endl
    << " 000||000" << std::endl
    << " 000||000" << std::endl
    << "   0||0" << std::endl
    << "    ||" << std::endl
    << "    ||" << std::endl
    << "  ------";
    
    new_file.close();
}

const char *ShrubberyCreationForm::FileNotOpenOrCreatedException::what() const throw()
{
    return "Can't open or create File";
}