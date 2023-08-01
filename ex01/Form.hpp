/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:17:52 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 16:17:52 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form(const std::string &name, const unsigned int reqGradeSign, const unsigned int reqGradeExec);

	Form(Form const &other);

	const Form &operator=(Form const &rhs);

	~Form();

	const std::string &getName() const;

	bool getIsSigned() const;

	void setIsSigned(bool isSigned);

	int getReqGradeSign() const;

	int getReqGradeExec() const;

	void beSigned(Bureaucrat &signer);

	class GradeTooHighException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

private:

	Form();

	const std::string _name;
	bool _isSigned;
	const int _reqGradeSign;
	const int _reqGradeExec;

};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //CPP05_Form_HPP
