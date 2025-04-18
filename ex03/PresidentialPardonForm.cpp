/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:53:37 by relamine          #+#    #+#             */
/*   Updated: 2025/04/18 15:53:41 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , target(target)
{
    std::cout << "Constructor of PresidentialPardonForm " << this->target << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form), target(form.target)
{
    if (this == &form)
    {
        return ;
    }
    std::cout << "Copy Constructor of PresidentialPardonForm " << this->target << " called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor of PresidentialPardonForm " << this->target << " called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
    if (this != &form)
    {
        AForm::operator=(form);
        std::cout << "Copy Assignment Operator of PresidentialPardonForm " << this->target << " called" << std::endl;
        this->target = form.target;
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &ex) const
{
    this->checkExecution(ex);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
