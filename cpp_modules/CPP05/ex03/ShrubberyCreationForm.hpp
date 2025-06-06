/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:17:56 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/17 18:31:34 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#include <fstream>
#include <string>

class AForm;

class ShrubberyCreationForm : public AForm 
{
  private:
    std::string _targetName;

  public:
    ShrubberyCreationForm();
    explicit ShrubberyCreationForm(const std::string &targetName);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
    
    void executer() const;
};

#endif
