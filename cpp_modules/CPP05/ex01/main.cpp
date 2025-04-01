/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:08:58 by dsamuel           #+#    #+#             */
/*   Updated: 2025/03/31 13:57:56 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Bureaucrat1", 2);
        Bureaucrat b2("Bureaucrat2", 50);

        Form f1("Form1", 5, 10);
        Form f2("Form2", 100, 100);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1);
        b2.signForm(f1);

        b2.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}