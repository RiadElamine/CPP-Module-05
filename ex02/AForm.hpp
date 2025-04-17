/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 06:59:17 by codespace         #+#    #+#             */
/*   Updated: 2025/04/17 15:16:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
        AForm();
        AForm(const std::string name, int grade_s, int grade_e);
        AForm(const AForm &b);
        AForm &operator=(const AForm &b);
        virtual ~AForm();
        std::string		getName() const;
        bool			getIs_signed() const;
        int				getGradeToSign() const;
        int				getGradeToExecute() const;
        void			beSigned(Bureaucrat const &b);
        virtual void	execute(Bureaucrat const & executor) const = 0;
        void			checkExecution(Bureaucrat const & executor) const;
    
        class FormNotSignedException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowForExecutionException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream& operator << (std::ostream &out, const AForm& f);