/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:02:21 by codespace         #+#    #+#             */
/*   Updated: 2025/04/17 14:58:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) , target(target)
{
    std::cout << "Constructor of RobotomyRequestForm " << this->target << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form), target(form.target)
{
    if (this == &form)
    {
        return ;
    }
    std::cout << "Copy Constructor of RobotomyRequestForm " << this->target << " called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor of RobotomyRequestForm " << this->target << " called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
    if (this != &form)
    {
        AForm::operator=(form);
        std::cout << "Copy Assignment Operator of RobotomyRequestForm " << this->target << " called" << std::endl;
        this->target = form.target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &ex) const
{
    this->checkExecution(ex);
    std::cout << "drilling noises :: Zzzzzzzzzzz ";
    
    srand(time(0));
    int random = rand() % 2;
    if (random == 0)
    {
        std::cout << this->target << " Faild to be robotomy" << std::endl;
        return ;
    }
    std::cout<< this->target << " has been robotomized successfully 50% of the time." << std::endl;
}
