/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:20:28 by relamine          #+#    #+#             */
/*   Updated: 2025/04/19 16:16:51 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
    std::cout << "Default constructor of Form " << this->name << " called" << std::endl;
}

Form::Form(const std::string name, int grade_s, int grade_e) : name(name), is_signed(false), grade_to_sign(grade_s), grade_to_execute(grade_e)
{
    std::cout << "Constructor of Form " << this->name << " called" << std::endl;
    if (grade_s < 1 || grade_e < 1)
        throw Form::GradeTooHighException();
    if (grade_s > 150 || grade_e > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &f) : name(f.name), is_signed(f.is_signed), grade_to_sign(f.grade_to_sign), grade_to_execute(f.grade_to_execute)
{
    if (this == &f)
    {
        return ;
    }
    std::cout << "Copy constructor of Form " << this->name << " called" << std::endl;
}

Form& Form::operator=(const Form &f)
{
    if (this != &f)
    {
        std::cout << "Copy assignment operator of Form " << this->name << " called" << std::endl;
        this->is_signed = f.is_signed;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Destructor of Form " << this->name << " called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIs_signed() const
{
    return (this->is_signed);
}

int Form::getGradeToSign() const
{
    return (this->grade_to_sign);
}

int Form::getGradeToExecute() const
{
    return (this->grade_to_execute);
}

std::ostream& operator << (std::ostream &out, const Form& f)
{
    out << "Form " << f.getName() << ": is_signed = " << f.getIs_signed() << ", grade_to_sign = " << f.getGradeToSign() << ", grade_to_execute = " << f.getGradeToExecute();
    return out;
}

void    Form::beSigned(Bureaucrat const &b)
{
    if (b.getGrade() > this->grade_to_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}
