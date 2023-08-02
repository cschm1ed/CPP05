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
#include <iostream>

int main() {
	Bureaucrat *Bert = nullptr;

	try {
		Bert = new Bureaucrat("Bert", 1);
		std::cout << "\n";
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n";

	try {
		Bureaucrat Malcolm("Malcolm", 0);
		std::cout << "\n";
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n";

	try {
		Bureaucrat Hannah("Hannah", 151);
		std::cout << "\n";
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n";

	Bert->decrementGrade(10);

	try {
		Bureaucrat Alberto("Alberto", 10);
		std::cout << "\n";
		try {
			Alberto.incrementGrade(100);
		} catch (const std::exception &e) {
			std::cerr << e.what() << "\n";
		}
		try {
			Alberto.decrementGrade(50);
		} catch (const std::exception &e) {
			std::cerr << e.what() << "\n";
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << *Bert << "\n";

	delete Bert;

	return 0;
}
