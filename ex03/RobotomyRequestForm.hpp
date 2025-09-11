#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Bureaucrat.hpp"
#include <ctime>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm: public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

        virtual void execute(Bureaucrat const & executor) const;
};

#endif