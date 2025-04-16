/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 23:15:56 by relamine          #+#    #+#             */
/*   Updated: 2025/04/16 15:54:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n----- grade too high -----" << std::endl;
    try
    {
        Form b("gradetoohighForm", 0, 8);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n----- grade too low -----" << std::endl;
    try
    {
        Form c("gradetoolow", 9, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n----- Bureaucrat successfully signs a Form -----" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 8);
        Form contract("Contract", 10, 6);
        std::cout << contract << std::endl;
        bob.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n----- Bureaucrat fails to sign Form (low grade) -----\n";
    try
    {
        Bureaucrat jim("Jim", 100);
        Form secret("SecretFile", 10, 6);
        std::cout << secret << std::endl;
        jim.signForm(secret);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n----- Form already signed -----\n";
    try
    {
        Bureaucrat riad("riad", 1);
        Form report("Report", 10, 5);
        riad.signForm(report); 
        riad.signForm(report);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
