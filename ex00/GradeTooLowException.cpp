#include "GradeTooLowException.hpp"

const char*	what() const throw() {
	return "Grade is too low: must be <= 150";
}
