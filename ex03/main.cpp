#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void test1(); 
void test2();
void test3(); 
void test4(); 

int main(void) {
    test1();
    test2();
    test3();
    test4();
    return 0;
}

void test1() {
    std::cout << "-------------- Test 1: robotomy request form (Success) --------------" << std::endl;
    try {
        Intern i;
        AForm* f;
        Bureaucrat b = Bureaucrat("Dima", 1);
        f = i.makeForm("robotomy request", "robot");
        std::cout << *f << std::endl;
        b.signForm(*f);
        std::cout << *f << std::endl;
        b.executeForm(*f);
        delete f;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test2() {
    std::cout << "-------------- Test 2: shrubbery creation form (Success) --------------" << std::endl;
    try {
        Intern i;
        AForm* f;
        Bureaucrat b = Bureaucrat("Dima", 1);
        f = i.makeForm("shrubbery creation", "shrubbery");
        std::cout << *f << std::endl;
        b.signForm(*f);
        std::cout << *f << std::endl;
        b.executeForm(*f);
        delete f;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test3() {
    std::cout << "-------------- Test 2: presidential pardon form (Success) --------------" << std::endl;
    try {
        Intern i;
        AForm* f;
        Bureaucrat b = Bureaucrat("Dima", 1);
        f = i.makeForm("presidential pardon", "president");
        std::cout << *f << std::endl;
        b.signForm(*f);
        std::cout << *f << std::endl;
        b.executeForm(*f);
        delete f;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test4() {
    std::cout << "-------------- Test 4: (failure - form not found) --------------" << std::endl;
    try {
        Intern i;
        AForm* f;
        Bureaucrat b = Bureaucrat("Dima", 1);
        f = i.makeForm("randome form name", "shrubbery");
        std::cout << *f << std::endl;
        b.signForm(*f);
        std::cout << *f << std::endl;
        b.executeForm(*f);
        delete f;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
