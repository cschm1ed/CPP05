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

class Bureaucrat {

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	virtual ~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &);
	const std::string &getName() const;
	void setGrade(int grade);
	int getGrade() const;

	void incrementGrade(unsigned int amount);
	void decrementGrade(unsigned int amount);

	class GradeTooHighException : std::exception {
	public:
		 virtual const char *what() const throw();
	};

	class GradeTooLowException : std::exception {
	public:
		virtual const char *what() const throw();
	};

private:

	const std::string	_name;
	int 				_grade;

};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &);

#endif //CPP05_BUREAUCRAT_HPP
