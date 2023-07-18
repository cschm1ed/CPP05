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
#include "Form.hpp"
#include <iostream>

int	main() {
	Bureaucrat* Bert = nullptr;

	try {
		Bert = new Bureaucrat("Bert", 10);
		std::cout << *Bert << "\n";
	} catch (const std::exception & e) {
		std::cerr << e.what() << "\n";
	}

	Form* Visa = nullptr;
	try {
		Visa = new Form("Visa", 10, 5);
		std::cout << *Visa << "\n";
	} catch (const std::exception & e) {
		std::cerr << e.what() << "\n";
	}

	try {
		Visa->beSigned(*Bert);
	} catch (const std::exception & e) {
		std::cerr << e.what() << "\n";
	}

	Form* Contract;
	try {
		Contract = new Form("Contract", 1, 1);
		std::cout << *Contract << "\n";
		try {
			Bert->signForm(*Contract);
		} catch (const std::exception & e) {
			std::cerr << e.what() << "\n";
		}
		try {
			Bert->incrementGrade(9);
		} catch (const std::exception & e) {
			std::cerr << e.what() << "\n";
		}
		try {
			Bert->signForm(*Contract);
		} catch (const std::exception & e) {
			std::cerr << e.what() << "\n";
		}
	} catch (const std::exception & e) {
		std::cerr << e.what() << "\n";
	}


	delete	Contract;
	delete	Bert;
	delete	Visa;

	return 0;
}
