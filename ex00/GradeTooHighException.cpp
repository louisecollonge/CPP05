#include "GradeTooHighException.hpp"

const char*	what() const throw() {
	return "Grade is too high: must be >= 1";
}

