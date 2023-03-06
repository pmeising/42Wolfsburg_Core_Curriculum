/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:01:38 by pmeising          #+#    #+#             */
/*   Updated: 2023/03/02 17:07:11 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <list>
# include <stack>
# include <algorithm>
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack& operator=(const MutantStack& rhs);
		~MutantStack();
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {return this->c.begin();} // Stack class initiated without an adapter specified, defaults to deque. Deque contains a protected member c, which is the sequence of data. This uses the standard iterators and we are able to access them through c.
		iterator end() {return this->c.end();}
};

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << B_BLUE << "Constructor call.\n" << DEFAULT;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj)
{
	std::cout << B_BLUE << "Copy constructor call.\n" << DEFAULT;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << B_BLUE << "Destructor call.\n" << DEFAULT;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
	std::cout << B_BLUE << "Assignment operator overload call.\n" << DEFAULT;
}

// Resources: 
// * https://gcc.gnu.org/onlinedocs/gcc-11.2.0/libstdc++/api/a05015.html
// * https://cplusplus.com/reference/stack/stack/?kw=stack
// * https://cplusplus.com/reference/deque/deque/

#endif
