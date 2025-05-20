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
        AForm* file = new ShrubberyCreationForm("File");

        try {
            bimo.executeForm(*file); // cause error bc not signed
        } catch (AForm::FileNotSignedException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        } catch (AForm::GradeTooLowException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        try {
            bimo.signForm(*file); // writes "Bimo signed..."
            bimo.executeForm(*file); // writes "Bimo executed..."
        } catch (AForm::GradeTooLowException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        } catch (AForm::FileNotSignedException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        delete file;
        std::cout << std::endl;
    }

// Robotomy
    {
        std::cout << PINK << "~ RobotomyRequestForm tests ~" << RESET << std::endl;
        Bureaucrat bouzoumbip("Bouzoumbip", 45);
        AForm* repertory = new RobotomyRequestForm("Repertory");

        try {
            bouzoumbip.executeForm(*repertory); // cause error bc not signed
        } catch (AForm::FileNotSignedException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        try {
            bouzoumbip.signForm(*repertory); // writes "Bouzoumbip signed..."
            bouzoumbip.executeForm(*repertory); // will try to execute
        } catch (AForm::GradeTooLowException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        } catch (AForm::FileNotSignedException &e) {
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
        AForm* sheet = new PresidentialPardonForm("Sheet");

        try {
            cocotte.signForm(*sheet);
            cocotte.executeForm(*sheet); // cause error bc grade is too low
        } catch (AForm::GradeTooLowException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        } catch (AForm::FileNotSignedException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        try {
            souverainCamomille.signForm(*sheet);
            souverainCamomille.executeForm(*sheet);
        } catch (AForm::GradeTooLowException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        } catch (AForm::FileNotSignedException &e) {
            std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
        }

        delete sheet;
        std::cout << std::endl;
    }

    return 0;
}
