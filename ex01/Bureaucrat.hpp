/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:16:31 by relamine          #+#    #+#             */
/*   Updated: 2025/04/18 15:21:34 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Form.hpp"

class Form;

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
		void			signForm(Form &f);
};

std::ostream& operator << (std::ostream &out, const Bureaucrat& f);
