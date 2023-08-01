/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:33:05 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 17:33:52 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(
		"PresidentialPardonForm for " + target, target, 25, 5) {
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialParonForm destuctor called\n";
}

void PresidentialPardonForm::executeAction() const {
	std::cout << _target << " has been pardoned by his grace Zaphod Beeblebrox\n";
}
