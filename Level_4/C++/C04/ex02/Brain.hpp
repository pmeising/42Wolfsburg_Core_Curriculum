/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:30:38 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/03 16:31:23 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>
# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"

class	Brain
{
	public:
		Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& rhs);
		~Brain();
		void	setIdea(const std::string idea);
		std::string getIdea(int i) const;

	private:
		unsigned int	_i; // indicates index of next empty thought slot.
		std::string	ideas[100];
};

#endif