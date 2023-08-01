/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:45:28 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/01 14:45:32 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_INTERN_HPP
#define CPP05_INTERN_HPP

#include <iostream>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <AForm.hpp>
#include <colors.hpp>

class Intern {

public:
	Intern();

	Intern(Intern const &other);

	~Intern();

	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string const &name, std::string const &target);

private:

};


#endif //CPP05_INTERN_HPP
