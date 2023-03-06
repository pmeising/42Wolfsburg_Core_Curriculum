/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:16:23 by pmeising          #+#    #+#             */
/*   Updated: 2023/03/02 16:57:10 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <numeric>
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

class	Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_vec;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& obj);
		Span& operator=(const Span& rhs);
		virtual ~Span();
		
		void	addNumber(int nbr);
		unsigned long	shortestSpan();
		unsigned long	longestSpan();
		std::vector<int>	get_vec(void);
};

// https://www.youtube.com/watch?v=2olsGf6JIkU

#endif