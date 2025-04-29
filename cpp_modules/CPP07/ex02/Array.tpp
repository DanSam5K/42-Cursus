/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:13:24 by dsamuel           #+#    #+#             */
/*   Updated: 2025/04/25 18:04:44 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _length(0) 
{
    std::cout << "[Array] Default Constructor invoked!" << std::endl;
    _data = new T[0];
}


template <typename T> 
Array<T>::Array(unsigned int n) : _length(n) 
{
    std::cout << "[Array] Parameterized constructor invoked! " << std::endl;
    this->_data = new T[n];
};


template <typename T>
Array<T>::Array(const Array& other)
{
    std::cout << "[Array] Copy constructor invoked!" << std::endl;
    _length = other.size();
    _data = new T[_length];
    for (unsigned int index = 0; index < _length; ++index)
    {
        _data[index] = other._data[index];
    }
    _length = other._length;
}


template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
  if (this != &other)
  {
    delete[] _data;
    _length = other.size();
    _data = new T[_length];
    for (unsigned int index = 0; index < _length; ++index)
      _data[index] = other._data[index];
  }
  return *this;
}

template <typename T>
Array<T>::~Array()
{
  delete[] _data;
  std::cout << "[Array] Destructor invoked!" << std::endl;
}


template <typename T>
unsigned int Array<T>::size() const
{
  return _length;
}


template <typename T>
T &Array<T>::operator[](unsigned int index)
{
  if (index >= _length)
    throw OutOfBoundsException();
  return _data[index];
}


template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
  return "Array index out of bounds!";
}
