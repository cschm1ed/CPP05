/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:04:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 14:15:32 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat constructor called\n";
}

void Bureaucrat::decrementGrade(unsigned int amount) {
	if (_grade + amount > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat " << _name << " grade decremented by" << amount << "\n";
	_grade += amount;
}

void Bureaucrat::incrementGrade(unsigned int amount) {
	if (_grade - amount < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << "Bureaucrat " << _name << " grade incremented by " << amount << "\n";
	_grade -= amount;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called\n";
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::setGrade(int grade) {
	_grade = grade;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	this->_grade = other._grade;
	return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called\n";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException";
}

void Bureaucrat::signForm(Form &toSign) {
	if (_grade > toSign.getReqGradeSign()) {
		std::cout << _name << " couldn't sign " << toSign.getName() << " because his grade is to low.\n";
		return ;
	}
	std::cout << _name << " signed " << toSign.getName();
	toSign.setIsSigned(true);
}
