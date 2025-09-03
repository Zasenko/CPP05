#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    void setGrade(int grade);
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &src);

    const std::string getName(void) const;
    int getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);

    void signForm(Form &form) const;

    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif