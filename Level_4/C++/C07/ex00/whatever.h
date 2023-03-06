/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 08:52:51 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/17 09:41:03 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H
# include <iostream>
# include <string>

template <class T>
void	swap(T& a, T& b)
{
	T	c;
	
	c = a;
	a = b;
	b = c;
}

template <class T>
T	min(T a, T b)
{
	if (a == b)
		return (b);
	else if (a > b)
		return (b);
	return (a);
}

template <class T>
T	max(T a, T b)
{
	if (a == b)
		return (b);
	else if (a > b)
		return (a);
	return (b);
}

#endif