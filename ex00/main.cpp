#include "Bureaucrat.hpp"

#define BOLD_RED    "\033[1;31m"
#define RESET	    "\033[0m"

int	main() {
	try {
        Bureaucrat a("Bouzoum", 0); // error: grade too high
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << BOLD_RED << "Error creating Bouzoum: " << e.what() << RESET << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << BOLD_RED << "Error creating Bouzoum: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat b("Cocotte", 151); // error: grade too low
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << BOLD_RED << "Error creating Cocotte: " << e.what() << RESET << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << BOLD_RED << "Error creating Cocotte: " << e.what() << RESET << std::endl;
    }

    try {
        Bureaucrat c("Bimo", 2);
        std::cout << c << std::endl; // writes: grade 2
        c.incrementGrade(); // becomes 1
        std::cout << c << std::endl; // writes: grade 1
        c.incrementGrade(); // error: too high bc < 1
        std::cout << c << std::endl; // will not be done bc of previous throw
        c.decrementGrade(); // will not be done bc of previous throw
        std::cout << c << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << BOLD_RED << e.what() << RESET << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << BOLD_RED << e.what() << RESET << std::endl;
    }

    return 0;
}
