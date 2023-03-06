/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:37:43 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 19:06:44 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <string>
# include <iostream>
# include <cstdlib>
# include <stdint.h>

class A;
class B;
class C;

class	Base
{
	public:
		virtual	~Base();
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif
