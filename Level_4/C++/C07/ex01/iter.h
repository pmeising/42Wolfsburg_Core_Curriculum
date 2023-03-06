/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:55:04 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/26 19:25:32 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H
# include "iostream"
#include <cstdlib>

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"


template	<class T>
void	iter(T *ptr, unsigned int len, void (*f)(T const& x))
{
	unsigned int	i = 0;

	while (i < len)
	{
		f(ptr[i]);
		i++;
	}
}

template <class T>
void	printing(T const& x)
{
	std::cout << x << "\n";
}

#endif