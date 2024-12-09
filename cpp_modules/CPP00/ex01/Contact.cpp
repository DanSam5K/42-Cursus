/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:06:36 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/09 17:14:05 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::SetContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret) {
    first_name = first;
    last_name = last;
    nickname = nick;
    phone_number = phone;
    darkest_secret = secret;
    initialized = true;
}

void Contact::PrintContact() {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

int Contact::ContactExists() {
    return (initialized);
}

std::string Contact::GetFirstName() {
    return (first_name);
}

std::string Contact::GetLastName() {
    return (last_name);
}

std::string Contact::GetNickname() {
    return (nickname);
}
