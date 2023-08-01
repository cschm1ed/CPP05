/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:13:20 by cschmied          #+#    #+#             */
/*   Updated: 2023/07/18 17:13:25 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP05_SHRUBBERYCREATIONFORM_HPP
#define CPP05_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm(const std::string &target);

	~ShrubberyCreationForm();

	class FileOpenException : public std::exception {
		virtual const char *what() const

		_NOEXCEPT;
	};

protected:
	void executeAction() const;

};


#endif //CPP05_SHRUBBERYCREATIONFORM_HPP
