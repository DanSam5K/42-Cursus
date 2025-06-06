/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:49:47 by dsamuel           #+#    #+#             */
/*   Updated: 2024/12/12 22:11:45 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main() {
    std::cout << "Welcome to your Phonebook!\n";
    sleep(2);
    std::system("clear");
    std::cout << "Loading...\n";
    sleep(1);
    std::system("clear");
    PhoneBook Book;
    int id = 0;

    while (1) {
        std::cout << "Please input ADD, SEARCH, or EXIT: ";
        std::string input;
        std::cin >> input;
        std::system("clear");
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        if (input == "ADD") {
            while (Book.isContactUsed(id)) {
                if (id == MaxId - 1) {
                    id = 0;
                    break;
                }
                id++;
            }
            std::string first;
            std::string last;
            std::string nick;
            std::string phone;
            std::string secret;

            std::system("clear");
            std::cout << "First Name: ";
            std::cin.ignore();
            while (first.empty()) {
                std::getline(std::cin, first);
                if (first.empty()) {
                    std::cout << "You must enter a first name!\n";
                    std::cout << "Please input your first name: ";
                }
            }
            std::cout << "\nLast Name: ";
            while (last.empty()) {
                std::getline(std::cin, last);
                if (last.empty()) {
                    std::cout << "You must enter a last name!\n";
                    std::cout << "Please input your last name: ";
                }
            }
            std::cout << "\nNickname: ";
            while (nick.empty()) {
                std::getline(std::cin, nick);
                if (nick.empty()) {
                    std::cout << "You must enter a nickname!\n";
                    std::cout << "Please input your nickname: ";
                }
            }
            std::cout << "\nPhone Number: ";
            while (true) {
                std::getline(std::cin, phone);
                if (phone.empty()) {
                    std::cout << "You must enter a phone number!\n";
                } else if (!std::all_of(phone.begin(), phone.end(), ::isdigit)) {
                    std::cout << "Invalid phone number. Please enter digits only: ";
                } else {
                    break; // Valid phone number
                }
            }
            std::cout << "\nDarkest Secret: ";
            while (secret.empty()) {
                std::getline(std::cin, secret);
                if (secret.empty()) {
                    std::cout << "You must enter a secret!\n";
                    std::cout << "Please input your secret: ";
                }
            }
            Book.SetContactId(id, first, last, nick, phone, secret);
        } else if (input == "SEARCH") {
            std::system("clear");
            Book.ListPhoneBook();
            std::cout << "\nPlease input the id of the contact you would like to see: ";
            std::string input;
            std::cin >> input;
            const char *input2 = input.c_str();
            int id = atoi(input2);
            if (id < 0 || id >= MaxId || !Book.isContactUsed(id) 
                || !std::all_of(input2, input2 + strlen(input2), ::isdigit)) {
                std::cout << "Invalid ID. Please try again.\n";
                continue;
            }
            std::system("clear");
            Book.IdPrintContact(id);
        } else if (input == "EXIT") {
            std::cout << "Goodbye!\n";
            return 0;
        }
    }
}
