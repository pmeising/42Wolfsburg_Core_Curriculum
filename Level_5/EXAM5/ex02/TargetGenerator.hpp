/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:12:28 by rkaufman          #+#    #+#             */
/*   Updated: 2023/04/11 14:45:42 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP
# include <map>
# include "ATarget.hpp"

class TargetGenerator
{
	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void		learnTargetType(ATarget * target);
		void		forgetTargetType(std::string const & targetName);
		ATarget *	createTarget(std::string const & targetName);

	protected:

	private:

		TargetGenerator(TargetGenerator & obj);
		TargetGenerator & operator=(TargetGenerator const & rhs);
		std::map<std::string, ATarget *> targets;
};

#endif