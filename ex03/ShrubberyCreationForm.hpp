#ifndef SHRUBBERY_REQUEST_FORM_HPP
#define SHRUBBERY_REQUEST_FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

        virtual void execute(Bureaucrat const & executor) const;

        class FileNotOpenOrCreatedException: public std::exception
        {
            public:
            virtual const char *what() const throw();
        };
};

#endif