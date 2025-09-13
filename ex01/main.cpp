#include "Bureaucrat.hpp"

void test1();
void test2();
void test3();

int main(void) {
    test1();
    test2();
    test3();
    return 0;
}

void test1() {
    std::cout << "-------------- Test 1 --------------"<< std::endl;
    std::cout << "---- 1.1 -----"<< std::endl;

    try {
        Form f("ImportantForm", 500, 20);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "---- 1.2 -----"<< std::endl;

    try {
        Form f("ImportantForm", -100, 20);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "---- 1.3 -----"<< std::endl;

    try {
        Form f("ImportantForm", 20, 200);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "---- 1.4 -----"<< std::endl;

    try {
        Form f("ImportantForm", 20, -200);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test2() {
    std::cout << "-------------- Test 2 --------------"<< std::endl;
    try {
        Bureaucrat b("Kate", 30);
        Form f("ImportantForm", 50, 20);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void test3() {
    std::cout << "-------------- Test 3 --------------"<< std::endl;
    try {
        Bureaucrat b("Kate", 100);
        Form f("ImportantForm", 50, 20);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
