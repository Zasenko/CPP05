#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
    public:
        Form();
        Form(std::string name, int grade_to_sign, int grade_to_execute);
        ~Form();
        Form(const Form &copy);
        Form &operator=(const Form &src);

        const std::string get_name() const;
        bool get_is_signed() const;
        const int get_grade_to_sign() const;
        const int get_grade_to_execute() const;

        void beSigned(const Bureaucrat &b);

    class GradeTooHighException: public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception {
        public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &src);

#endif