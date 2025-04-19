/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relamine <relamine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:16:28 by relamine          #+#    #+#             */
/*   Updated: 2025/04/19 17:09:01 by relamine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    grade = 150;
	std::cout << "Default constructor of Bureaucrat " << this->name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& f)
{
    if (this == &f)
    {
        return ;
    }
	std::cout << "Copy constructor of Bureaucrat " << this->name << " called" << std::endl;
	this->grade = f.grade;
}

Bureaucrat::Bureaucrat(const std::string _name, int grade) : name(_name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Constructor of Bureaucrat " << this->name << " called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& f)
{
	if (this != &f)
	{
        std::cout << "Copy assignment operator of Bureaucrat " << this->name << " called" << std::endl;
        this->grade = f.grade;
    }
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor of Bureaucrat " << this->name << " called" << std::endl;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::increment_grade()
{
    if (grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement_grade()
{
    if (grade == 150)
        throw GradeTooLowException();
    this->grade++;
}

std::ostream& operator << (std::ostream &out, const Bureaucrat& f)
{
	out << f.getName() << ", bureaucrat grade " << f.getGrade() << ".";
	return (out);
}

void			Bureaucrat::signForm(AForm &f)
{
    if (f.getIs_signed())
    {
        std::cout << this->name << " couldn't sign " << f.getName() << " because it's already signed." << std::endl;
        return ;
    }
    try 
    {
        f.beSigned(*this);
    }
    catch (...)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because Grade to sign too low!." << std::endl;
        throw;
    }
    std::cout << this->name << " signed " << f.getName() << std::endl;
}

void			Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << "❌💥💥💥💥Error💥💥💥💥❌" << std::endl;
        throw;
    }
    std::cout << this->name << " executed " << form.getName() << std::endl;
}
