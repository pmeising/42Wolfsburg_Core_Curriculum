/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:46:09 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/06 22:35:51 by pmeising         ###   ########.fr       */
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
		std::stack<int>		_A;
		std::stack<char>	_B;
		std::string			_input;
		RPN(const RPN& obj);
		RPN& 	operator=(const RPN& rhs);
		int		inputCheck(const std::string input);
		int		operate();
		void	printResult();
	public:
		RPN();
		~RPN();
		int		calculate(const std::string input);
};

#endif