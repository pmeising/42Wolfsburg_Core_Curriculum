/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:58:28 by pmeising          #+#    #+#             */
/*   Updated: 2023/01/23 12:03:59 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact()
{
	firstName = "unknown";
	lastName = "unknown";
	nickName = "unknown";
	phoneNumber = "unknown";
	darkestSecret = "unknown";
}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	if (!fn.empty() && !ln.empty() && !nn.empty() && !pn.empty() && !ds.empty())
	{
		firstName = fn;
		lastName = ln;
		nickName = nn;
		phoneNumber = pn;
		darkestSecret = ds;
	}
	else
		std::cout << "Invalid input, couldn't save contact.\n";
}

int	Contact::set_info(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	if (!fn.empty() && !ln.empty() && !nn.empty() && !pn.empty() && !ds.empty())
	{
		firstName = fn;
		lastName = ln;
		nickName = nn;
		phoneNumber = pn;
		darkestSecret = ds;
		return (0);
	}
	else
		return (1);
}

std::string	Contact::get_info(std::string var)
{
	if (var == "firstName")
		return (firstName);
	else if (var == "lastName")
		return (lastName);
	else if (var == "nickName")
		return (nickName);
	else if (var == "phoneNumber")
		return (phoneNumber);
	else if (var == "darkestSecret")
		return (darkestSecret);
	return ("unknown");
}
