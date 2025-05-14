#include "Bureaucrat.hpp"
#include "Form.hpp"
#define ORANGE	"\033[38;5;214m"
#define BLUE	"\033[34m"
#define RESET	"\033[0m"

int	main() {
    try {
        Bureaucrat  bimo("Bimo", 1);
        std::cout << ORANGE << bimo << RESET << std::endl;

        Bureaucrat  cocotte("Cocotte", 5);
        std::cout << ORANGE << cocotte << RESET << std::endl << std::endl;
        
        Form        paper("paper", 2, 1);
        std::cout << BLUE << paper << RESET << std::endl;
        
        Form        file("file", 150, 150);
        std::cout << BLUE << file << RESET << std::endl;
        
        bimo.signForm(paper);
        cocotte.signForm(paper);
        bimo.signForm(file);
        cocotte.signForm(file);
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
