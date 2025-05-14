#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define ORANGE	    "\033[38;5;214m"
#define BLUE	    "\033[34m"
#define BOLD_RED    "\033[1;31m"
#define RESET	    "\033[0m"

int	main() {

// Shrubbery
    try {
        Bureaucrat  bimo("Bimo", 1);
        AForm*  paper = new ShrubberyCreationForm("home");

        std::cout << ORANGE << bimo << RESET << std::endl;
        std::cout << BLUE << paper << RESET << std::endl;

        bimo.signForm(*paper);
        bimo.executeForm(*paper);

        delete paper;
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << BOLD_RED << e.what() << RESET << std::endl;
    }

// Robotomy
    try {
        Bureaucrat  cocotte("Cocotte", 5);
        AForm*  file = new RobotomyRequestForm("home");

        std::cout << ORANGE << cocotte << RESET << std::endl;
        std::cout << BLUE << file << RESET << std::endl;

        cocotte.signForm(*file);
        cocotte.executeForm(*file);

        delete file;
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << BOLD_RED << e.what() << RESET << std::endl;
    }

// Presidential pardon
    try {
        Bureaucrat  bouzoum("Bouzoum", 5);
        AForm*  sheet = new PresidentialPardonForm("home");

        std::cout << ORANGE << bouzoum << RESET << std::endl;
        std::cout << BLUE << sheet << RESET << std::endl;

        bouzoum.signForm(*sheet);
        bouzoum.executeForm(*sheet);

        delete sheet;
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << BOLD_RED << e.what() << RESET << std::endl;
    }

    return 0;
}
