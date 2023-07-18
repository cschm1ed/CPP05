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

int	main() {
	Bureaucrat* Bert = nullptr;

	try {
		Bert = new Bureaucrat("Bert", 1);
	} catch (const std::exception & e) {
		std::cerr <<  e.what() << "\n";
	}

	try {
		Bureaucrat	Malcolm("Malcolm", 0);
	} catch (const std::exception & e) {
		std::cerr << e.what() << "\n";
	}

	try {
		Bureaucrat	Hannah("Hannah", 151);
	} catch (const std::exception & e) {
		std::cerr << e.what() << "\n";
	}

	Bert->decrementGrade(10);

	try {
		Bureaucrat	Alberto("Alberto", 10);
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

	delete	Bert;

	return 0;
}
