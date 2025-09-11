#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {

    try {
        Bureaucrat b = Bureaucrat("Dima", 150);
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        // b.incrementGrade();
        // std::cout << b << std::endl;
        // PresidentialPardonForm pf = PresidentialPardonForm();
        // b.signForm(pf);

        // b.executeForm(pf);


        // RobotomyRequestForm rf = RobotomyRequestForm();
        // b.signForm(rf);
        // b.executeForm(rf);

        ShrubberyCreationForm sf = ShrubberyCreationForm("HELLO-FORM");
        b.signForm(sf);
        b.executeForm(sf);

    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}