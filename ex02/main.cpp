#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test1(); 
void test2(); 
void test3();
void test4();
void test5();

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

void test1() {
    std::cout << "-------------- Test 1: Constructor --------------\n" << std::endl;

    std::cout << "----- 1.1 ShrubberyCreationForm -----" << std::endl;
    try {
        ShrubberyCreationForm f("Shrubbery");
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "----- 1.2 RobotomyRequestForm -----" << std::endl;
    try {
        RobotomyRequestForm f("Robot");
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "----- 1.3 PresidentialPardonForm -----" << std::endl;
    try {
        PresidentialPardonForm f("President");
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test2() {
    std::cout << "\n-------------- Test 2: Signing (Success) --------------\n" << std::endl;
    std::cout << "----- 2.1 ShrubberyCreationForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 1);
        ShrubberyCreationForm f("Shrubbery");
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 2.2 RobotomyRequestForm -----" << std::endl;
    try {
        Bureaucrat b("Oliver", 1);
        RobotomyRequestForm f("Robot");
        std::cout << f << std::endl;
        b.signForm(f);  // Should fail (too low)
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 2.3 PresidentialPardonForm -----" << std::endl;
    try {
        Bureaucrat b("Nick", 1);
        PresidentialPardonForm f("President");
        std::cout << f << std::endl;
        b.signForm(f);  // Should fail (too low)
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test3() {
    std::cout << "\n-------------- Test 3: Signing (Failure) --------------\n" << std::endl;

    std::cout << "----- 3.1 ShrubberyCreationForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 150);
        ShrubberyCreationForm f("Shrubbery");
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 3.2 RobotomyRequestForm -----" << std::endl;
    try {
        Bureaucrat b("Oliver", 150);
        RobotomyRequestForm f("Robot");
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 3.3 PresidentialPardonForm -----" << std::endl;
    try {
        Bureaucrat b("Nick", 150);
        PresidentialPardonForm f("President");
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test4() {
    std::cout << "\n-------------- Test 4: Execute Forms (Success) --------------\n" << std::endl;

    std::cout << "----- 4.1 ShrubberyCreationForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 1);
        ShrubberyCreationForm f("Shrubbery");
        b.signForm(f);
        std::cout << f << std::endl;
        b.executeForm(f);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 4.2 RobotomyRequestForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 1);
        RobotomyRequestForm f("Robo");
        b.signForm(f);
        std::cout << f << std::endl;
        b.executeForm(f);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 4.3 PresidentialPardonForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 1);
        PresidentialPardonForm f("President");
        b.signForm(f);
        std::cout << f << std::endl;
        b.executeForm(f);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test5() {
    std::cout << "\n-------------- Test 5: Execute Forms (Failure) --------------\n" << std::endl;

    std::cout << "----- 5.1 ShrubberyCreationForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 140);
        ShrubberyCreationForm f("Shrubbery");
        b.signForm(f);
        std::cout << f << std::endl;
        b.executeForm(f);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 5.2 RobotomyRequestForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 70);
        RobotomyRequestForm f("Robo");
        b.signForm(f);
        std::cout << f << std::endl;
        b.executeForm(f);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "----- 5.3 PresidentialPardonForm -----" << std::endl;
    try {
        Bureaucrat b("Bob", 20);
        PresidentialPardonForm f("President");
        b.signForm(f);
        std::cout << f << std::endl;
        b.executeForm(f);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
