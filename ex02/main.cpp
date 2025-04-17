/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:15:56 by relamine          #+#    #+#             */
/*   Updated: 2025/04/17 16:13:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << "\n****************** Robotomy Request Form ******************" << std::endl;
        Bureaucrat bob("Bob", 45);
        std::cout << "-------------------------" << std::endl;
        RobotomyRequestForm form1("riad");
        std::cout << "-------------------------" << std::endl;
        bob.signForm(form1);
        std::cout << "-------------------------" << std::endl;
        bob.executeForm(form1);

        std::cout << "\n         *********** grade to execute too low ***********" << std::endl;
        Bureaucrat Sbobo("Sbobo", 72);
        std::cout << "-------------------------" << std::endl;
        Sbobo.executeForm(form1);
    }
    catch (const std::exception &e)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "couldn't execute the form because: " << e.what() << std::endl;
    }


    try
    {
        std::cout << "\n****************** ShrubberyCreationForm ******************" << std::endl;
        Bureaucrat bob("Bob", 1);
        std::cout << "-------------------------" << std::endl;
        ShrubberyCreationForm form1("home");
        std::cout << "-------------------------" << std::endl;
        bob.signForm(form1);
        std::cout << "-------------------------" << std::endl;
        bob.executeForm(form1);

        std::cout << "\n        *********** Failed to write ASCII trees if fail to open file ***********" << std::endl;
        ShrubberyCreationForm form2("office");
        bob.signForm(form2);
        bob.executeForm(form2);
    }
    catch (const std::exception &e)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "couldn't execute the form because: " << e.what() << std::endl;
    }


    try
    {
        std::cout << "\n****************** Presidential Pardon Form ******************" << std::endl;
        Bureaucrat bob("Bob", 5);
        std::cout << "-------------------------" << std::endl;
        PresidentialPardonForm form1("salah");
        std::cout << "-------------------------" << std::endl;
        bob.signForm(form1);
        std::cout << "-------------------------" << std::endl;
        bob.executeForm(form1);

        std::cout << "\n        *********** Form doesn't signed ***********" << std::endl;
        std::cout << "-------------------------" << std::endl;
        PresidentialPardonForm form2("twichiya");
        std::cout << "-------------------------" << std::endl;
        bob.executeForm(form2);
    }
    catch (const std::exception &e)
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "couldn't execute the form because: " << e.what() << std::endl;
    }

    return 0;
}
