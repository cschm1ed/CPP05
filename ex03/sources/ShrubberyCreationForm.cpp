/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:13:20 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 17:13:28 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubber creation form for " + target,
																				target, 145, 137) {
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called\n";
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw() {
	return "Could not open file Exception";
}

void ShrubberyCreationForm::executeAction() const {

	std::ofstream fs(_target + "_shrubbery", std::ios_base::out);

	if (!fs) {
		throw ShrubberyCreationForm::FileOpenException();
	}
	fs <<
	   """      _-_\n"
	   "    /~~   ~~\\\n"
	   " /~~         ~~\\\n"
	   "{               }\n"
	   " \\  _-     -_  /\n"
	   "   ~  \\\\ //  ~\n"
	   "_- -   | | _- _\n"
	   "  _ -  | |   -_\n"
	   "      // \\\\""";

	fs.close();
}
