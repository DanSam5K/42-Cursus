/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:43:18 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/29 12:45:59 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "MutantStack.hpp"

// #include <iostream>
// #include "MutantStack.hpp"
// #include <stack>
// #include <deque>
// #include <iterator>
// #include <limits>
// #include <stdexcept>
// #include <string>

// template<typename T>
// void printStack(const MutantStack<T>& stack) {
//     typename MutantStack<T>::const_iterator it = stack.begin();
//     typename MutantStack<T>::const_iterator end = stack.end();

//     std::cout << "[ ";
//     while (it != end) {
//         std::cout << *it << " ";
//         ++it;
//     }
//     std::cout << "] (size: " << stack.size() << ")\n";
// }

// int main() {
//     std::cout << "=== Testing MutantStack ===\n";

//     MutantStack<int> mstack;

//     // Test push and top
//     mstack.push(10);
//     mstack.push(20);
//     mstack.push(30);
//     std::cout << "Top: " << mstack.top() << "\n"; // 30

//     // Test pop
//     mstack.pop();
//     std::cout << "After pop, top: " << mstack.top() << "\n"; // 20

//     // Test size
//     std::cout << "Size: " << mstack.size() << "\n";

//     // Test iterator
//     mstack.push(40);
//     mstack.push(50);
//     mstack.push(60);
//     std::cout << "Contents via iterator: ";
//     printStack(mstack);

//     // Test modification via iterator
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
//         *it += 1;
//     }
//     std::cout << "After incrementing each element: ";
//     printStack(mstack);

//     // // Test const correctness
//     // const MutantStack<int>& constRef = mstack;
//     // std::cout << "Const iteration: ";
//     // for (MutantStack<int>::const_iterator it = constRef.begin(); it != constRef.end(); ++it) { // Use begin() and end()
//     //     std::cout << *it << " ";
//     // }
//     // std::cout << "\n";

//     // Test copy constructor
//     MutantStack<int> copy(mstack);
//     std::cout << "Copied stack: ";
//     printStack(copy);

//     // Test assignment
//     MutantStack<int> assigned;
//     assigned = mstack;
//     std::cout << "Assigned stack: ";
//     printStack(assigned);

//     // Compatibility with std::stack
//     std::stack<int> s(mstack);
//     std::cout << "Top of std::stack copy: " << s.top() << "\n";

//     // Edge case: empty stack
//     MutantStack<int> empty;
//     std::cout << "Empty stack size: " << empty.size() << "\n";
//     std::cout << "Iterating over empty stack: ";
//     for (auto it = empty.begin(); it != empty.end(); ++it)
//         std::cout << *it << " "; // Should not print
//     std::cout << "(done)\n";

//     return 0;
// }

// // int main() {
// //     MutantStack<int> mstack;

// //     mstack.push(5);
// //     mstack.push(17);

// //     std::cout << "Top element: " << mstack.top() << std::endl;

// //     mstack.pop();
// //     std::cout << "Size after pop: " << mstack.size() << std::endl;

// //     mstack.push(3);
// //     mstack.push(5);
// //     mstack.push(737);
// //     mstack.push(0);

// //     std::cout << "Elements in stack:" << std::endl;
// //     MutantStack<int>::iter it = mstack.begin();
// //     MutantStack<int>::iter ite = mstack.end();

// //     for (; it != ite; ++it) {
// //         std::cout << *it << std::endl;
// //     }

// //     return 0;
// // }

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }