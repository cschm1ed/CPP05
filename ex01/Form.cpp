/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:17:52 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 16:22:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, const unsigned int reqGradeSign, const unsigned int reqGradeExec)
		: _name(name), _isSigned(false), _reqGradeSign(reqGradeSign), _reqGradeExec(reqGradeExec) {
	std::cout << "Form constructor called\n";
}

Form::~Form() {
	std::cout << "Form destructor called\n";
}

const std::string &Form::getName() const {
	return _name;
}

bool Form::isIsSigned() const {
	return _isSigned;
}

void Form::setIsSigned(bool isSigned) {
	_isSigned = isSigned;
}

int Form::getReqGradeSign() const {
	return _reqGradeSign;
}

int Form::getReqGradeExec() const {
	return _reqGradeExec;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form: " << form._name << " _isSigned: " << form._isSigned << " _reqGradeSign: " << form._reqGradeSign
	   << " _reqGradeExec: " << form._reqGradeExec;
	return os;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form::GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form::GradeTooHighException";
}

void Form::beSigned(Bureaucrat &signer) {
	if (signer.getGrade() > _reqGradeSign || !_isSigned) {
		throw Form::GradeTooLowException();
	}
	std::cout << "Form " << _name << " was signed by " << signer << "\n";
	_isSigned = true;
}
