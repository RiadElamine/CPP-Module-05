/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:20:00 by codespace         #+#    #+#             */
/*   Updated: 2025/04/17 18:20:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default constructor of Intern called" << std::endl;
}

Intern::Intern(const Intern& f)
{
    if (this == &f)
    {
        return ;
    }
	std::cout << "Copy constructor of Intern called" << std::endl;
}

Intern& Intern::operator=(const Intern& f)
{
	if (this != &f)
	{
        std::cout << "Copy assignment operator of Intern called" << std::endl;
    }
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Destructor of Intern called" << std::endl;
}

AForm* Intern::CreateShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::CreateRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::CreatePresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

int	Intern::whois( std::string type)
{
	std::string types[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	for (int i = 0; i < 3; i++)
	{
		switch (types[i].compare(type))
		{
			case 0 :
				return (i);
		}
	}
	return (-1);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{

    AForm* (Intern::* createForm[3])(std::string target) = { &Intern::CreateShrubbery, &Intern::CreateRobotomy, &Intern::CreatePresidential};

    switch (whois(formName))
	{
		case 0:
			return((this->*createForm[0])(target));
		case 1:
			return((this->*createForm[1])(target));
		case 2:
			return((this->*createForm[2])(target));
		default:
			std::cout << "Intern can't create this form" << std::endl;
			break;
	}
	return (NULL);
}