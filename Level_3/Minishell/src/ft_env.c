/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-carv <bde-carv@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:59:34 by bde-carv          #+#    #+#             */
/*   Updated: 2022/11/28 19:51:39 by bde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	Prints the ENV list.
*/
int	ft_env(t_list **dup_env)
{
	t_list	*tmp;

	tmp = *dup_env;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

/*
* to comply with norminette in ft_check_doll;
*/
void	ft_dumdum(char *raw_input, int pos)
{
	ft_get_str(raw_input, pos);
	raw_input = ft_replace_str(raw_input, pos);
}

/*
* comply with norminette below 25lines
*/
void	ft_bubidubi(t_cmd *cmd_iterator, int *pid)
{
	ft_interpret(cmd_iterator);
	ft_execute_process_2(cmd_iterator, pid);
}

/*
* just for norminette below 25 lines;
*/
void	ft_shorten(int *pid)
{
	g_mini.exit = 1;
	free (pid);
	ft_free_input();
}
