#include "Bureaucrat.hpp"
#include "Form.hpp"

#define ORANGE	    "\033[38;5;214m"
#define BLUE	    "\033[34m"
#define BOLD_RED    "\033[1;31m"
#define RESET	    "\033[0m"

int	main() {
    try {
        Bureaucrat  bimo("Bimo", 1);
        std::cout << ORANGE << bimo << RESET << std::endl; // writes "Bimo, bureaucrat grade 1."

        Bureaucrat  cocotte("Cocotte", 5);
        std::cout << ORANGE << cocotte << RESET << std::endl << std::endl; // writes Cocotte, "bureaucrat grade 5."
        
        Form        paper("paper", 2, 1);
        std::cout << BLUE << paper << RESET << std::endl; // writes all info about paper
        
        Form        file("file", 150, 150);
        std::cout << BLUE << file << RESET << std::endl; // writes all info about file
        
        bimo.signForm(paper); // writes: "Bimo signed paper"
        bimo.signForm(file); // writes: "Bimo signed file"
        cocotte.signForm(file); // writes: "Cocotte signed file"
        cocotte.signForm(paper); // error bc grade too low
        std::cout << std::endl;
    } catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } catch (Form::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
