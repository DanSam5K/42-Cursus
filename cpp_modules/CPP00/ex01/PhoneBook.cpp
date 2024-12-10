/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:05:31 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/10 10:36:50 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::GetFirstName(int id) {
    return (Contacts[id].GetFirstName());
}

std::string PhoneBook::GetLastName(int id) {
    return (Contacts[id].GetLastName());
}

std::string PhoneBook::GetNickname(int id) {
    return (Contacts[id].GetNickname());
}

void
PhoneBook::SetContactId(int id, std::string first, std::string last, std::string nick, std::string phone, std::string secret) {
    Contacts[id].SetContact(first, last, nick, phone, secret);
}

void PhoneBook::IdPrintContact(int id) {
    Contacts[id].PrintContact();
}

int PhoneBook::isContactUsed(int id) {
    return (Contacts[id].ContactExists());
}

void TruncateAndReplace(std::string &str) {
    if (str.length() > MaxLength) {
        str.resize(MaxLength - 1);
        std::cout << str << ".";
    }
}

void PhoneBook::ListPhoneBook() {
    std::string separator = "+-----+----------+----------+----------+----------+\n";
    std::cout << separator 
                << std::right
                << "|" << std::setw(5) << "ID"
                << "|" << std::setw(10) << "Index"
                << "|" << std::setw(10) << "First Name"
                << "|" << std::setw(10) << "Last Name"
                << "|" << std::setw(10) << "Nickname"
                << "|" << std::endl;
    std::cout << separator;
     for (int id = 0; Contacts[id].ContactExists() && id < MaxId; id++) {
        std::string firstname = GetFirstName(id);
        TruncateAndReplace(firstname);
        std::string lastname = GetLastName(id);
        TruncateAndReplace(lastname);
        std::string nickname = GetNickname(id);
        TruncateAndReplace(nickname);
        std::cout << "|" << std::setw(5) << id << "|";
        std::cout << std::setw(10) << id + 1 << "|";
        std::cout << std::setw(10) << firstname << "|";
        std::cout << std::setw(10) << lastname << "|";
        std::cout << std::setw(10) << nickname << "|" << std::endl;
        std::cout << separator;
    }
    std::cout << separator;
}
