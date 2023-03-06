/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:39:43 by pmeising          #+#    #+#             */
/*   Updated: 2023/03/02 17:06:29 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		std::stack<int>	stack;
		stack.push(1);
		std::cout << "Stack value: " << stack.top() << "\n";
		stack.push(2);
		std::cout << "Stack value: " << stack.top() << "\n";
		stack.push(1);
		std::cout << "Stack value: " << stack.top() << "\n";
		stack.pop();
		std::cout << "Stack value: " << stack.top() << "\n";
	}
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		// std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	
	{
		std::cout << B_GREEN << "\n############ Own tests ################\n\n";
		MutantStack<std::string>	mStack;
		mStack.push("Hello");
		mStack.push("World!");
		mStack.push("What a wonderful ");
		mStack.push("day!");
		std::cout << mStack.top() << "\n";
		mStack.pop();
		std::cout << mStack.top() << "\n";
		MutantStack<std::string>::iterator	begin = mStack.begin();
		MutantStack<std::string>::iterator	end = mStack.end();
		while (begin != end)
		{
			std::cout << B_PINK << "Content: " << *begin << "\n" << DEFAULT;
			begin++;
		}
		begin = mStack.begin();
		end = mStack.end();
		while (end != begin)
		{
			std::cout << B_YELLOW << "Content: " << *end << "\n" << DEFAULT;
			--end;
		}
	}
	return 0;
}
