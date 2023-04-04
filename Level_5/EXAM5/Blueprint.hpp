/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Blueprint.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:40:23 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/04 16:04:28 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLUEPRINT
# define BLUEPRINT

# include <iostream>
# include <string>

class Blueprint
{
	private:
		std::string		_name;
		unsigned int	_id;
	public:
		Blueprint(); // default constr.
		Blueprint(std::string name); // param constr.
		Blueprint(std::string name, unsigned int i); // param constr.
		Blueprint(const Blueprint& obj); // copy constr.
		~Blueprint(); // destr.
		Blueprint&		operator=(const Blueprint& rhs); // assignment operator overload

		std::string		getName(void) const;
		unsigned int	getId(void) const;
};

#endif