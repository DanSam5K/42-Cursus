/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:41:31 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/30 14:39:52 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <exception>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <deque>
#include <vector>

class PmergeMe 
{
    private:
        std::vector<int> _vectorContainer;
        std::deque<int> _dequeContainer;

        template <typename Container>
        static bool confirmIsSorted(Container &container);

        template <typename Container>
        static void insertionSort(Container &container);
        
        template <typename Container>
        static void fordJohnsonSort(Container &container);

        // template <typename Container>
        // void mergeSortContainer(Container &container, Container &leftContainer, Container &rightContainer);

    public:
        explicit PmergeMe(std::vector<int> containerList);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        ~PmergeMe();

        
        void sort();

        class DuplicatedNumbersException : public std::exception
        {
            const char *what() const throw();
        };
};

#endif // EX02_PMERGEME_HPP