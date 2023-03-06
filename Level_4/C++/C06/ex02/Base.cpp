/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:45:56 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 19:28:21 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ctime"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base()
{
	std::cout << "Base destructor called.\n";
}

Base* Base::generate(void)
{
	Base	*base;
	if (!(time(NULL) % 3))
	{
		base = new (A);
		std::cout << "A\n";
	}
	else if (!(time(NULL) % 2))
	{
		base = new (B);
		std::cout << "B\n";
	}
	else
	{
		base = new (C);
		std::cout << "C\n";
	}
	return (base);
}

void	Base::identify(Base* p)
{
	A	*a;
	B	*b;
	
	if ((a = dynamic_cast<A*>(p)))
		std::cout << "p is of type A\n";
	else if ((b = dynamic_cast<B*>(p)))
		std::cout << "p is of type B\n";
	else
		std::cout << "p is of type C\n";
}

void	Base::identify(Base& p)
{
	Base	a;
	Base	b;
	Base	c;
	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "p is of type A\n";
	}
	catch(const std::exception& e){}
	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << "p is of type B\n";
	}
	catch(const std::exception& e){}
	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << "p is of type C\n";
	}
	catch(const std::exception& e) {}
}
