#include "Bureaucrat.hpp"

int main(void) {

    try {
        Bureaucrat b = Bureaucrat("Dima", 1);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}