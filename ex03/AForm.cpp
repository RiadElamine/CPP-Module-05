/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:45:46 by relamine          #+#    #+#             */
/*   Updated: 2025/04/19 16:27:47 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "Default constructor of Form " << this->name << " called" << std::endl;
}

AForm::AForm(const std::string name, int grade_s, int grade_e) : name(name), is_signed(false), grade_to_sign(grade_s), grade_to_execute(grade_e)
{
    std::cout << "Constructor of Form base " << this->name << " called" << std::endl;
    if (grade_s < 1 || grade_e < 1)
        throw AForm::GradeTooHighException();
    if (grade_s > 150 || grade_e > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &f) : name(f.name), is_signed(f.is_signed), grade_to_sign(f.grade_to_sign), grade_to_execute(f.grade_to_execute)
{
    if (this == &f)
    {
        return ;
    }
    std::cout << "Copy constructor of Form base " << this->name << " called" << std::endl;
}

AForm& AForm::operator=(const AForm &f)
{
    if (this != &f)
    {
        std::cout << "Copy assignment operator of Form base " << this->name << " called" << std::endl;
        this->is_signed = f.is_signed;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Destructor of Form base " << this->name << " called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIs_signed() const
{
    return (this->is_signed);
}

int AForm::getGradeToSign() const
{
    return (this->grade_to_sign);
}

int AForm::getGradeToExecute() const
{
    return (this->grade_to_execute);
}

std::ostream& operator << (std::ostream &out, const AForm& f)
{
    out << "Form " << f.getName() << ": is_signed = " << f.getIs_signed() << ", grade_to_sign = " << f.getGradeToSign() << ", grade_to_execute = " << f.getGradeToExecute();
    return out;
}

void    AForm::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->grade_to_sign)
        throw AForm::GradeTooLowException();
    this->is_signed = true;
}


const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}


const char* AForm::GradeTooLowForExecutionException::what() const throw()
{
    return ("Bureaucrat's grade is too low to execute the form!");
}

void    AForm::checkExecution(Bureaucrat const & ex) const
{
    if (!this->is_signed)
        throw AForm::FormNotSignedException();
    if (ex.getGrade() > this->grade_to_execute)
        throw AForm::GradeTooLowForExecutionException();
}