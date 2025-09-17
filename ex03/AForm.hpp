#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
    public:
        AForm();
        AForm(std::string name, int grade_to_sign, int grade_to_execute);
        virtual ~AForm();
        AForm(const AForm &copy);
        AForm &operator=(const AForm &src);

        const std::string get_name() const;
        bool get_is_signed() const;
        int get_grade_to_sign() const;
        int get_grade_to_execute() const;

        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException: public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception {
        public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException: public std::exception {
        public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &src);

#endif
