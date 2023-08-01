/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:07 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 14:04:07 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <iostream>

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// RobotomyRequestForm: Required grades: sign 72, exec 45
// PresidentialPardonForm: Required grades: sign 25, exec 5

int main() {
	Bureaucrat *JoeBiden = nullptr;
	AForm *robotomyRequestForm = nullptr;
	AForm *shrubberyCreationForm = nullptr;
	AForm *presidentialPardonForm = nullptr;
	Intern					intern;

	std::cout << "\n\n";

	try {
		JoeBiden = new Bureaucrat("JoeBiden", 1);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n\n";
	std::cout << GREEN << "------------Robotomy------------\n" << RESET;

	robotomyRequestForm = static_cast<RobotomyRequestForm *>(intern.makeForm("robotter request", "Dog"));
	robotomyRequestForm = static_cast<RobotomyRequestForm *>(intern.makeForm("robotomy request", "Dog"));
	try {
		robotomyRequestForm->beSigned(*JoeBiden);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	try {
		robotomyRequestForm->execute(*JoeBiden);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n\n";

	std::cout << GREEN << "-----------Shrubbery-----------\n" << RESET;

	shrubberyCreationForm = static_cast<ShrubberyCreationForm *>(intern.makeForm("shrubbery", "allerpark"));
	shrubberyCreationForm = intern.makeForm("shrubbery creation", "White House garden");
	try {
		shrubberyCreationForm->beSigned(*JoeBiden);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	try {
		shrubberyCreationForm->execute(*JoeBiden);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n\n";

	std::cout << GREEN << "------------Pardon-------------\n" << RESET;

	presidentialPardonForm = static_cast<PresidentialPardonForm *>(intern.makeForm("pardon", "Donald Trump"));
	presidentialPardonForm = static_cast<PresidentialPardonForm *>(intern.makeForm("presidential pardon", "Charles Manson"));
	if (presidentialPardonForm == nullptr) {
		std::cout << RED << "pointer = null\n" << RESET;
		return 1;
	}
	try {
		JoeBiden->signForm(*presidentialPardonForm);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	try {
		JoeBiden->executeForm(*presidentialPardonForm);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n\n";

	delete shrubberyCreationForm;
	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete JoeBiden;
	return 0;
}
