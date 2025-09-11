#include "Intern.hpp"

AForm *Intern::makeForm(std::string name, std::string target)
{
        std::cout << "makeForm!!!!!" << std::endl;

    std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    int lev = -1;
    for (int i = 0; i < 3 && lev == -1; i++)
    {
        if (name == forms[i]) {
            lev = i;
            break;
        }
    }

    AForm *form = NULL;

    // TODO: malloc error?
    switch (lev) {
        case 0:
            form = new RobotomyRequestForm(target);
            break;
        case 1:
            form = new ShrubberyCreationForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
    }
    if (form == NULL) {
        std::cout << "Form " << name << " not found" << std::endl;
    }
    else {
        std::cout << "Intern creates ";
        switch (lev) {
        case 0:
            std::cout << "Robotomy Request form" << std::endl;
            break;
        case 1:
            std::cout << "Shrubbery Creation form" << std::endl;
            break;
        case 2:
            std::cout << "Presidential Pardon form" << std::endl;
            break;
        }
    }
    return form;
}