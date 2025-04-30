/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:29:01 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/26 18:49:27 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
    std::cout << "Default constructor invoked!" << std::endl;
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other)
{
    std::cout << "Copy constructor invoked!" << std::endl;
    *this = other;
}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
    std::cout << "Assignment operator invoked!" << std::endl;
    if (this != &other) {
        std::stack<T, Container>::operator=(other);
    }
    return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
    std::cout << "Destructor invoked!" << std::endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() 
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() 
{
    return this->c.end();
}
