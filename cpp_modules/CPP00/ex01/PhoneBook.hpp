/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:05:50 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/09 17:25:44 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_PHONEBOOK_HPP
#define EX01_PHONEBOOK_HPP

#include "Contact.hpp"
#include "header.hpp"

class PhoneBook {
private:
    Contact Contacts[MaxId];
    
    std::string GetFirstName(int id);

    std::string GetLastName(int id);

    std::string GetNickname(int id);

public:
    void
    SetContactId(int id, std::string first, std::string last, std::string nick, std::string phone, std::string secret);
    
    void IdPrintContact(int id);
    
    int isContactUsed(int id);

    void ListPhoneBook();

};

#endif //EX01_PHONEBOOK_HPP