/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:48:42 by relamine          #+#    #+#             */
/*   Updated: 2025/04/17 15:17:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string   name;
		int                 grade;

		class GradeTooHighException : public std::exception 
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &b);
        Bureaucrat &operator=(const Bureaucrat &b);
        ~Bureaucrat();

        std::string		getName() const;
        int				getGrade() const;
		void			increment_grade();
		void			decrement_grade();
		void			signForm(AForm &f);
		void			executeForm(AForm const & form);
};

std::ostream& operator << (std::ostream &out, const Bureaucrat& f);
