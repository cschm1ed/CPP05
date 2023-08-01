/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:45:28 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/01 14:45:41 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern() {
	std::cout << "Intern default constructor called\n";
}

Intern::~Intern() {
	std::cout << "Intern default destructor called\n";
}

Intern::Intern(Intern const &other) {
	(void) other;
	std::cout << "Intern copy constructor called\n";
}

Intern &Intern::operator=(Intern const &rhs) {
	(void) rhs;
	return *this;
}

AForm *Intern::makeForm(std::string const &name, std::string const &target) {
	int i = 0;
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	std::cout << "Intern was assigned to make " << name << " for: " << target << "\n";

	while (i < 3) {
		if (forms[i] == name)
			break;
		i++;
	}

	switch (i) {
		case 0:
			std::cout << BLUE << "Intern creates " << name << " for" << target << "\n" << RESET;
			return new RobotomyRequestForm(target);
			break;
		case 1:
			std::cout << BLUE << "Intern creates " << name << " for" << target << "\n" << RESET;
			return new ShrubberyCreationForm(target);
			break;
		case 2:
			std::cout << BLUE << "Intern creates " << name << " for" << target << "\n" << RESET;
			return new PresidentialPardonForm(target);
			break;
		default:
			std::cout << RED << "Intern couldnt find " << name << " for" << target << "\n" << RESET;
			return nullptr;
	}
}
