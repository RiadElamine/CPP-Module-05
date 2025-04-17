/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:02:27 by codespace         #+#    #+#             */
/*   Updated: 2025/04/17 16:11:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137) , target(target)
{
    std::cout << "Constructor of ShrubberyCreationForm " << this->target << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), target(form.target)
{
    if (this == &form)
    {
        return ;
    }
    std::cout << "Copy Constructor of ShrubberyCreationForm " << this->target << " called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor of ShrubberyCreationForm " << this->target << " called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
    if (this != &form)
    {
        AForm::operator=(form);
        std::cout << "Copy Assignment Operator of ShrubberyCreationForm " << this->target << " called" << std::endl;
        this->target = form.target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &ex) const
{
    this->checkExecution(ex);
    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    file << "               ,@@@@@@@,\n"
     << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
     << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
     << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
     << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
     << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
     << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
     << "       |o|        | |         | |\n"
     << "       |.|        | |         | |\n"
     << "\\\\ ._\\\\//_/__/  ,\\\\_//__\\\\/.  \\\\_//__/_" <<  std::endl;
    file.close();
}
