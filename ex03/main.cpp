#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main(void) {

    Intern someRandomIntern;
    AForm* rrf;
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        if (rrf == NULL) return 0;
        Bureaucrat b = Bureaucrat("Dima", 200);

        b.signForm(*rrf);
        b.executeForm(*rrf);

        delete rrf;

    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    if (rrf != NULL) delete rrf;

    return 0;
}