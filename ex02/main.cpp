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

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// RobotomyRequestForm: Required grades: sign 72, exec 45
// PresidentialPardonForm: Required grades: sign 25, exec 5

int main() {
	Bureaucrat *JoeBiden = nullptr;
	RobotomyRequestForm *robotomyRequestForm = nullptr;
	ShrubberyCreationForm *shrubberyCreationForm = nullptr;
	PresidentialPardonForm *presidentialPardonForm = nullptr;

	std::cout << "\n\n";

	try {
		JoeBiden = new Bureaucrat("JoeBiden", 1);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n\n";
	std::cout << "------------Robotomy------------\n";
	try {
		robotomyRequestForm = new RobotomyRequestForm("Dog");
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
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

	std::cout << "------------Pardon-------------\n";

	try {
		presidentialPardonForm = new PresidentialPardonForm("Charles Manson");
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
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

	std::cout << "-----------Shrubbery-----------\n";

	try {
		shrubberyCreationForm = new ShrubberyCreationForm("White House garden");
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
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

	delete shrubberyCreationForm;
	delete presidentialPardonForm;
	delete robotomyRequestForm;
	delete JoeBiden;
	return 0;
}
