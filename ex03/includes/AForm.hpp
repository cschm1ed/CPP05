/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:17:52 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 16:17:52 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_AFORM_HPP
#define CPP05_AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(const std::string &name, const std::string &target, const unsigned int reqGradeSign,
		  const unsigned int reqGradeExec);

	AForm(AForm const &other);

	virtual ~AForm() = 0;


	const std::string &getName() const;

	bool isIsSigned() const;

	void setIsSigned(bool isSigned);

	int getReqGradeSign() const;

	int getReqGradeExec() const;

	void beSigned(Bureaucrat &signer);

	const std::string &getTarget() const;

	class GradeTooHighException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

	class FormNotSignedException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

	void execute(Bureaucrat const &executor) const;

	virtual void executeAction() const = 0;

protected:

	AForm();

	AForm &operator=(AForm const &rhs);

	const std::string _name;
	const std::string _target;
	bool _isSigned;
	const int _reqGradeSign;
	const int _reqGradeExec;

};

std::ostream &operator<<(std::ostream &os, const AForm &form);


#endif //CPP05_AFORM_HPP
