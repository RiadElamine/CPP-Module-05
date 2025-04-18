/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:16:34 by relamine          #+#    #+#             */
/*   Updated: 2025/04/18 15:17:02 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "* Valid construction & Valid grade changes" << std::endl;
    try
    {
        Bureaucrat f("Frank", 100);
        std::cout << f << std::endl;
        f.decrement_grade();
        std::cout << "After decrement: " << f << std::endl;
        f.increment_grade();
        std::cout << "After increment: " << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n* grade too high" << std::endl;
    try
    {
        Bureaucrat b("Bob", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n* grade too low" << std::endl;
    try
    {
        Bureaucrat c("Charlie", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n* Increment beyond limit" << std::endl;
    try
    {
        Bureaucrat d("Diana", 1);
        std::cout << d << std::endl;
        d.increment_grade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n* Decrement beyond limit" << std::endl;
    try
    {
        Bureaucrat e("Eve", 150);
        std::cout << e << std::endl;
        e.decrement_grade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
