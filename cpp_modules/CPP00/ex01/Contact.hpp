/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:54:00 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/09 17:10:29 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_CONTACT_HPP
#define EX01_CONTACT_HPP

#include <iostream>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    bool initialized;

public:
    Contact() : initialized(false) {};
    
    void SetContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
    
    void PrintContact();

    int ContactExists();

    std::string GetFirstName();

    std::string GetLastName();

    std::string GetNickname();
};


#endif //EX01_CONTACT_HPP