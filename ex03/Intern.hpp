/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:19:02 by relamine          #+#    #+#             */
/*   Updated: 2025/04/19 17:19:04 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		const std::string   name;
		int                 grade;

		class GradeTooHighException : public std::exception 
		{
			const char* what() const throw();
		};

    public:
        Intern();
        Intern(const Intern &b);
        Intern &operator=(const Intern &b);
        ~Intern();
		AForm* makeForm(std::string formName, std::string target);
		AForm* CreateShrubbery(std::string target);
		AForm* CreateRobotomy(std::string target);
		AForm* CreatePresidential(std::string target);
		int		whois( std::string type);

};