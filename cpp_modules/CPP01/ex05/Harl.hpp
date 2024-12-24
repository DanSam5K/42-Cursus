/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:24:05 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/24 20:26:05 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX05_HARL_CPP
#define EX05_HARL_CPP

#include "Harl.hpp"
#include <iostream>

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
public:
    void complain(std::string level);
};

#endif //EX05_HARL_CPP