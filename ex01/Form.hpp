/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:20:25 by relamine          #+#    #+#             */
/*   Updated: 2025/04/18 15:21:53 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string   name;
		bool                is_signed;
        const int           grade_to_sign;
        const int           grade_to_execute;

		class GradeTooHighException : public std::exception 
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};

    public:
        Form();
        Form(const std::string name, int grade_s, int grade_e);
        Form(const Form &b);
        Form &operator=(const Form &b);
        ~Form();
        std::string		getName() const;
        bool			getIs_signed() const;
        int				getGradeToSign() const;
        int				getGradeToExecute() const;
        void			beSigned(Bureaucrat const &b);
};

std::ostream& operator << (std::ostream &out, const Form& f);