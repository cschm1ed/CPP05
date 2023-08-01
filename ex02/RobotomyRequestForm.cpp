/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:30:42 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 17:30:58 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm for " + target, target,
																			72, 45) {
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotmyRequestForm destructor called\n";
}

void RobotomyRequestForm::executeAction() const {
	std::cout << "* --- drilling --- *\n";
	srand(time(0));
	if (rand() % 2) {
		std::cout << _target << " has been robotomized succesfully\n";
		return;
	}
	std::cout << _target << " could not be robotomized\n";

}
