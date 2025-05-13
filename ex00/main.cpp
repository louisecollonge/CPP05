#include "Bureaucrat.hpp"

int	main() {
	try {
        Bureaucrat a("Bouzoum", 0); // should throw
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Cocotte", 151); // should throw
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Bimo", 2);
        std::cout << c << std::endl;
        c.incrementGrade(); // becomes 1
        std::cout << c << std::endl;
        c.incrementGrade(); // should throw
        std::cout << c << std::endl;
        c.decrementGrade(); // will not be done bc of previous throw
        std::cout << c << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
