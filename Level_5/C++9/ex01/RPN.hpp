/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:46:09 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/06 21:02:09 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <iostream>
# include <stack>

class RPN
{
	private:
		std::stack<int>	_A;
		std::stack<int>	_B;
		std::string		_input;
		int				_result;
	public:
		RPN();
		~RPN();
		RPN(const RPN& obj);
		RPN& operator=(const RPN& rhs);
		int	calculate(const std::string input);
		int	inputCheck(const std::string input);
		
};

#endif