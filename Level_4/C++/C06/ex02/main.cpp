/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:37:27 by pmeising          #+#    #+#             */
/*   Updated: 2023/02/16 19:19:57 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	Base	base;
	Base	*ptr;
	Base	ref;

	ptr = base.generate();
	base.identify(ptr);

	base.identify(*ptr);
	delete ptr;
}
