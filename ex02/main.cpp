#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test1();  // Constructor tests (valid/invalid)
void test2();  // Signing tests
void test3();  // Execution tests (success)
void test4();  // Execution tests (fail due to grade)
void test5();  // Re-execution or double sign tests

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

void test1() {
    std::cout << "-------------- Test 1: Constructor Validation --------------" << std::endl;

    try {
        ShrubberyCreationForm f1("Home");
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "ShrubberyCreationForm Error: " << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm f2("Bender");
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "RobotomyRequestForm Error: " << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm f3("Alice");
        std::cout << f3 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "PresidentialPardonForm Error: " << e.what() << std::endl;
    }
}

void test2() {
    std::cout << "-------------- Test 2: Signing Forms --------------" << std::endl;

    try {
        Bureaucrat bob("Bob", 50);
        ShrubberyCreationForm f("Garden");
        std::cout << f << std::endl;
        bob.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("oliver", 150);
        RobotomyRequestForm f("Robot");
        std::cout << f << std::endl;
        alice.signForm(f);  // Should fail (too low)
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Nick", 150);
        PresidentialPardonForm f("Presiden");
        std::cout << f << std::endl;
        alice.signForm(f);  // Should fail (too low)
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test3() {
    std::cout << "-------------- Test 3: Execute Forms (Success) --------------" << std::endl;

    try {
        Bureaucrat exec("Exec", 1);

        ShrubberyCreationForm shrub("Park");
        shrub.beSigned(exec);
        shrub.execute(exec);  // Should create file

        RobotomyRequestForm robo("Robo");
        robo.beSigned(exec);
        robo.execute(exec);  // Should print drilling noise + result

        PresidentialPardonForm pardon("Pardoned");
        pardon.beSigned(exec);
        pardon.execute(exec);  // Should print pardon message

    } catch (std::exception &e) {
        std::cerr << "Execution Error: " << e.what() << std::endl;
    }
}

void test4() {
    std::cout << "-------------- Test 4: Execute Forms (Fail - grade too low) --------------" << std::endl;

    try {
        Bureaucrat low("Olga", 150);
        ShrubberyCreationForm shrub("FailPark");
        shrub.beSigned(low);  // Should throw or fail here if grade too low
        shrub.execute(low);  // Should fail (low grade)
    } catch (std::exception &e) {
        std::cerr << "Execution Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat mid("Bob", 150);
        RobotomyRequestForm robo("FailRobo");
        robo.beSigned(mid);  // maybe success
        robo.execute(mid);  // Should fail due to exec grade (usually 45 or lower required)
    } catch (std::exception &e) {
        std::cerr << "Execution Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat mid("Dima", 150);
        PresidentialPardonForm robo("FailRobo");
        robo.beSigned(mid);  // maybe success
        robo.execute(mid);  // Should fail due to exec grade (usually 45 or lower required)
    } catch (std::exception &e) {
        std::cerr << "Execution Error: " << e.what() << std::endl;
    }
}

void test5() {
    std::cout << "-------------- Test 5: Re-sign and Re-execute --------------" << std::endl;

    try {
        Bureaucrat john("John", 1);
        PresidentialPardonForm form("John");

        john.signForm(form);
        john.signForm(form);  // Signing twice (should handle gracefully)

        form.execute(john);
        form.execute(john);   // Executing twice (should work, no state change expected)
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
