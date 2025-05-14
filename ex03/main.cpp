#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define ORANGE	    "\033[38;5;214m"
#define BLUE	    "\033[34m"
#define BOLD_RED    "\033[1;31m"
#define PINK	 	"\033[0;35m"
#define RESET	    "\033[0m"

int	main() {
    Intern  bimo;
    Bureaucrat  cocotte("Cocotte", 1);

    AForm* form = bimo.makeForm("ShrubberyCreationForm", "home");
    AForm* file = bimo.makeForm("RobotomyRequestForm", "home");
    AForm* repertory = bimo.makeForm("PresidentialPardonForm", "home");
    AForm* wrongForm = bimo.makeForm("wrongForm", "home");
    std::cout << std::endl;

    cocotte.signForm(*form);
    cocotte.executeForm(*form);
    std::cout << std::endl;

    cocotte.signForm(*file);
    cocotte.executeForm(*file);
    std::cout << std::endl;

    cocotte.signForm(*repertory);
    cocotte.executeForm(*repertory);
    std::cout << std::endl;

    delete form;
    delete file;
    delete repertory;
    delete wrongForm;

    return 0;
}
