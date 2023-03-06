/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:07:50 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/26 19:29:56 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <cstdlib>
# include <exception>

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

template	<class T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& obj);
		~Array();

		Array& operator=(const Array<T>& rhs);
		T&	operator[](unsigned int i);
		unsigned int	size() const;

	private:
		T*				_array;
		unsigned int	_size;
};

template <class T>
Array<T>::Array() : _array(NULL), _size(0)
{
	std::cout << "Default constructor call.\n";
}

template <class T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	if (this->_array)
		delete[] this->_array;
	this->_array = new T[n]();
	std::cout << "Parameter constructor call.\nArray of size " << n << " created.\n";
}


// Need to initialize the _array first, before it can be deleted. :D 
template <class T>
Array<T>::Array(const Array<T>& obj) : _array(NULL), _size(obj.size())
{
	unsigned int	size;
	size = obj.size();

	if (this->_array)
	{
		delete[] this->_array;
		_array = NULL;
	}
	this->_array = new T[size]();
	for (unsigned int i = 0; i < size; i++)
		this->_array[i] = obj._array[i];
}


template <class T>
Array<T>::~Array()
{
	if (this->_array)
		delete[] this->_array;
	std::cout << "Default destructor call.\n";
}

// ########################## Operator overloads #########################

template <class T>
Array<T>&	Array<T>::operator=(const Array<T>& rhs)
{
	unsigned int	size;
	size = rhs.size();

	if (this->_array)
		delete[] _array;
	this->_array = new T[size]();
	for (int i = 0; i < size; i++)
		this->_array[i] = rhs._array[i];
	return (*this);	
}

template <class T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= this->_size)
		throw std::exception();
	return (this->_array[i]);
}


// ################################# Member functions #########################

template <class T>
unsigned int	Array<T>::size() const
{
	// The sizeof() returned a wrong value. Now creating a variable _size to store initial size in.
	return (this->_size);
}

#endif