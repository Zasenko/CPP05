#include "Bureaucrat.hpp"

void test1();
void test2();
void test3();
void test4();
void test5();

int main(void) {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}

void test1() {
    std::cout << "-------------- Test 1: Constructor (Success) --------------"<< std::endl;
    try {
        Bureaucrat b("Dima", 1);
        std::cout << b << std::endl;
    } catch(const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test2() {
    std::cout << "-------------- Test 2: Constructor (Failure) --------------"<< std::endl;
    try {
        Bureaucrat b("Ben", -5);
        std::cout << b << std::endl;
    } catch(const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test3() {
    std::cout << "-------------- Test 3: Constructor (Failure)  --------------"<< std::endl;
    try {
        Bureaucrat b("Kate", 180);
        std::cout << b << std::endl;
    } catch(const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test4() {
    std::cout << "-------------- Test 4: increment Grade --------------"<< std::endl;
    try {
        Bureaucrat b("Sara", 5);
        std::cout << b << std::endl;

        for (int i = 0; i < 100; i++) {
            b.incrementGrade();
            std::cout << b << std::endl;
        }
    } catch(const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test5() {
    std::cout << "-------------- Test 5: decrement Grade --------------"<< std::endl;
    try {
        Bureaucrat b("Norbert", 140);
        std::cout << b << std::endl;

        for (int i = 0; i < 100; i++) {
            b.decrementGrade();
            std::cout << b << std::endl;
        }
    } catch(const Bureaucrat::GradeTooHighException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const Bureaucrat::GradeTooLowException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
