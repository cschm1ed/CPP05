/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 14:04:51 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_BUREAUCRAT_HPP
#define CPP05_BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

public:
	Bureaucrat(const std::string &name, int grade);

	Bureaucrat(Bureaucrat const &other);

	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &);

	const std::string &getName() const;

	void setGrade(int grade);

	int getGrade() const;

	void incrementGrade(unsigned int amount);

	void decrementGrade(unsigned int amount);

	void signForm(Form &toSign);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

private:

	Bureaucrat();

	const std::string _name;
	int _grade;

};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &);

#endif //CPP05_BUREAUCRAT_HPP
