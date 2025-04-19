/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:43:44 by relamine          #+#    #+#             */
/*   Updated: 2025/04/19 17:16:06 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    AForm* rrf;
    try
    {
        Intern someRandomIntern;
        Bureaucrat b("Bureaucrat", 1);
        std::cout << "-----------------------------" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (!rrf)
            return 1;
        b.signForm(*rrf);
        std::cout << "-----------------------------" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    delete rrf;
    return 0;
}
