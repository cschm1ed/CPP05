/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:17:52 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 16:22:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, const std::string & target, const unsigned int reqGradeSign, const unsigned int reqGradeExec)
		: _name(name), _isSigned(false), _reqGradeSign(reqGradeSign), _reqGradeExec(reqGradeExec) {
	std::cout << "AForm constructor called\n";
}

AForm::~AForm() {
	std::cout << "AForm destructor called\n";
}

AForm::AForm(const AForm &other) : _name(other.getName()), _target(other.getTarget()), _reqGradeSign(other.getReqGradeSign()), _reqGradeExec(other.getReqGradeExec()){
	std::cout << "copy assignment constructor called\n";
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::isIsSigned() const {
	return _isSigned;
}

void AForm::setIsSigned(bool isSigned) {
	_isSigned = isSigned;
}

int AForm::getReqGradeSign() const {
	return _reqGradeSign;
}

int AForm::getReqGradeExec() const {
	return _reqGradeExec;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "AForm: " << form.getName() << "target: " << form.getTarget() << " _isSigned: " << form.isIsSigned() << " _reqGradeSign: " << form.getReqGradeSign()
	   << " _reqGradeExec: " << form.getReqGradeExec();
	return os;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm::GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm::GradeTooHighException";
}

void AForm::beSigned(Bureaucrat &signer) {
	if (signer.getGrade() > _reqGradeSign) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "AForm " << _name << " was signed by " << signer << "\n";
	_isSigned = true;
}

const std::string &AForm::getTarget() const {
	return _target;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > _reqGradeExec) {
		throw AForm::GradeTooLowException();
	}
	std::cout << executor << " is executing " << *this << "\n";
	executeAction();
}
