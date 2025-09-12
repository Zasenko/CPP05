#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern: Default constractor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern: Copy constractor called" << std::endl;
    (void) copy;
}

Intern::~Intern()
{
    std::cout << "Intern: Default destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    std::cout << "Intern: Assignment operator called" << std::endl;
    (void) src;
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    int lev = -1;
    for (int i = 0; i < 3 && lev == -1; i++) {
        if (name == forms[i]) {
            lev = i;
            break;
        }
    }
    AForm *form = NULL;
    switch (lev) {
        case 0:
            form = new RobotomyRequestForm(target);
            std::cout << "Intern creates Robotomy Request form" << std::endl;
            break;
        case 1:
            form = new ShrubberyCreationForm(target);
            std::cout << "Intern creates Shrubbery Creation form" << std::endl;
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            std::cout << "Intern creates Presidential Pardon form" << std::endl;
            break;
        default:
            std::cout << "Form " << name << " not found" << std::endl;
            break;
    }
    return form;
}