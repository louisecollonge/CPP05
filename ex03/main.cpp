#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main() {
    Intern  bimo;
    Bureaucrat  cocotte("Cocotte", 140);

    AForm* form = bimo.makeForm("Shrubbery creation", "form");
    AForm* file = bimo.makeForm("Robotomy request", "file");
    AForm* repertory = bimo.makeForm("Presidential pardon", "repertory");
    AForm* wrongForm = bimo.makeForm("wrong", "wrongForm");

    std::cout << std::endl;
    
    try {
        cocotte.signForm(*form);
        cocotte.executeForm(*form);
        std::cout << std::endl;
    } catch (AForm::FileNotSignedException &e) {
        std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        cocotte.signForm(*file);
        cocotte.executeForm(*file);
        std::cout << std::endl;
    } catch (AForm::FileNotSignedException &e) {
        std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        cocotte.signForm(*repertory);
        cocotte.executeForm(*repertory);
        std::cout << std::endl;
    } catch (AForm::FileNotSignedException &e) {
        std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << BOLD_RED << "Error: " << e.what() << RESET << std::endl;
    }

    delete form;
    delete file;
    delete repertory;
    delete wrongForm;

    return 0;
}
