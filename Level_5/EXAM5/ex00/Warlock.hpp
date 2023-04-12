/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:31:03 by pmeising          #+#    #+#             */
/*   Updated: 2023/04/12 10:42:08 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK
# define WARLOCK
# include <string>
# include <iostream>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		Warlock();
		Warlock(const Warlock& obj);
		Warlock&	operator=(const Warlock& rhs);

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();
		const std::string&	getName(void) const;
		const std::string&	getTitle(void) const;
		void				setTitle(const std::string& title);
		void				introduce() const;
};

#endif
