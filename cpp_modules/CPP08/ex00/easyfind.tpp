/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:19:39 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/26 17:25:59 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
void easyfind(T container, int valueToBeFound)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), valueToBeFound);
    
    if (iter == container.end()) {
        throw ValueNotFoundException();
    }
    
    std::cout << "Value " << valueToBeFound << " found at position "
              << std::distance(container.begin(), iter) << std::endl;
}

const char* ValueNotFoundException::what() const throw()
{
    return "[Error] Value not found in the container.";
}