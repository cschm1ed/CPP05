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

Form::Form() : _name("default"), _isSigned(0), _reqGradeSign(0), _reqGradeExec(0) {
	std::cout << "Form default constructor called\n";
}

Form::Form(Form const &other) : _name(other.getName()), _isSigned(other._isSigned),
								_reqGradeSign(other.getReqGradeSign()), _reqGradeExec(other.getReqGradeExec()) {
	std::cout << "Form copy constructor called\n";
}

const Form &Form::operator=(const Form &rhs) {
	_isSigned = rhs._isSigned;
	return *this;
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
	os << "Form: " << form.getName() << " _isSigned: " << form.getIsSigned() << " _reqGradeSign: "
	   << form.getReqGradeSign()
	   << " _reqGradeExec: " << form.getReqGradeExec();
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
