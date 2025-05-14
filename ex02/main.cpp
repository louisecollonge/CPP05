#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define ORANGE	    "\033[38;5;214m"
#define BLUE	    "\033[34m"
#define BOLD_RED    "\033[1;31m"
#define PINK	 	"\033[0;35m"
#define RESET	    "\033[0m"

int	main() {
// Shrubbery
    {
        std::cout << PINK << "~ ShrubberyCreationForm tests ~" << RESET << std::endl;
        Bureaucrat bimo("Bimo", 1);
        AForm* file = new ShrubberyCreationForm("file");

        try {
            bimo.executeForm(*file); // cause error bc not signed
        } catch (std::exception &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        try {
            bimo.signForm(*file);
            bimo.executeForm(*file);
        } catch (std::exception &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        delete file;
        std::cout << std::endl;
    }

// Robotomy
    {
        std::cout << PINK << "~ RobotomyRequestForm tests ~" << RESET << std::endl;
        Bureaucrat bouzoumbip("Bouzoumbip", 45);
        AForm* repertory = new RobotomyRequestForm("repertory");

        try {
            bouzoumbip.signForm(*repertory);
            bouzoumbip.executeForm(*repertory);
        } catch (std::exception &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        delete repertory;
        std::cout << std::endl;
    }

// Presidential pardon
    {
        std::cout << PINK << "~ PresidentialPardonForm tests ~" << RESET << std::endl;
        Bureaucrat cocotte("Cocotte", 6);
        Bureaucrat souverainCamomille("Souverain Camomille", 5);
        AForm* sheet = new PresidentialPardonForm("sheet");

        try {
            cocotte.signForm(*sheet);
            cocotte.executeForm(*sheet); // cause error bc grade is too low
        } catch (std::exception &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        try {
            souverainCamomille.signForm(*sheet);
            souverainCamomille.executeForm(*sheet);
        } catch (std::exception &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        delete sheet;
        std::cout << std::endl;
    }

    return 0;
}
