/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:54:45 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/26 19:28:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }


int	main()
{
	{
		int	array[90];

		for (int i = 0; i < 90; i++)
			array[i] = rand();
		iter(array, 90, printing<int>);
		std::cout << "Just the first 10: \n";
		iter(array, 10, printing<int>);
	}
	
	{
		std::string		array[90];
		
		for (int i = 0; i < 90; i++)
			array[i] = 'H';
		iter(array, 90, printing<std::string>);
	}

	std::cout << B_GREEN << "Now the Eval_sheet provided tests:\n\n" << DEFAULT;
	
	{
		int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
		Awesome tab2[5];

		iter(tab, 5, print<int>);
		iter(tab2, 5, print<Awesome>);
	}
}
