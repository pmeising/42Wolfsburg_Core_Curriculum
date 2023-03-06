/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_vars_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:42:08 by bde-carv          #+#    #+#             */
/*   Updated: 2022/11/29 15:23:33 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	Finds and replaces the "$?" with the exit status value.
	replaces the string content with the exit status.
*/
void	ft_replace_dollar_question_mark(char *raw_input, int pos)
{
	char	*exit_status_str;
	char	*before;
	char	*after;
	char	*half_str;
	int		i;

	i = 0;
	before = malloc(sizeof(char) * ft_strlen(raw_input));
	while (raw_input[i] && i < pos)
	{
		before[i] = raw_input[i];
		i++;
	}
	before[i] = '\0';
	after = strdup(&raw_input[pos + 2]);
	exit_status_str = ft_itoa(g_mini.exit_status);
	half_str = ft_strjoin(before, exit_status_str);
	free (before);
	free (exit_status_str);
	free (g_mini.raw_input);
	g_mini.raw_input = ft_strjoin(half_str, after);
	free (half_str);
	free (after);
}

/*
*	Walks through the input string and looks for a dollar signs ($).
*	Once found, it checks, whether it is followed by...
*	... a questionmark (?), in which case we show the most recently 
*		executed foreground pipeline.
*	... a quotationmark (" or '), in which case we replace 
*		the $ with a blankspace.
*	... a valid environment variable, in which case we insert the content
*		of the env into the string using ft_str_join.
*
*	1 would be outer quote, -1 inner quote and 0 no quote(closed quote);
*	34 = double quotes; 39 = single quotes;
*	all $ that are not interpreted will be deleted by shifting 
*	the string one position to the left
*	(last else-if statement);
*	edge case: $(PATH) should throw an error. Unable to handle it at this point
*	not required by subject pdf. --> see comment in 
*/
void	ft_env_vars(char *raw_input)
{
	int	pos;
	int	j;
	int	single_quotes;
	int	double_quotes;

	pos = 0;
	j = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (raw_input[pos])
	{
		ft_quotes(raw_input, &single_quotes, &double_quotes, &pos);
		if (raw_input[pos] == '$' && single_quotes == 1)
		{
			while (raw_input[pos] != 39)
				pos++;
			single_quotes = 0;
		}
		if (ft_check_doll(raw_input, &pos) == NULL)
			break ;
		j++;
		pos++;
	}
}

/*
*	checks if there are still interpretable dollar signs left in the string
*	If outer_quotes are single quotes -> do not interpret the $
*	If outer_quotes are double quotes -> do interpret the $
*	Returns 1 if a $ still has to be interpreted.
*	Returns 0 if no $ has to be interpreted anymore.
*
*	34 == double quote; 39 == single quote;
*	1 would be outer quote, -1 inner quote and 0 no quote;

* 	double    single	interpret
*	1			0		1
*	1			-1		1
*	0			0		1
*	-1			1		0
*	0			1		0
*/
void	ft_dollar_sign(void)
{
	int		i;
	int		single_quotes;
	int		double_quotes;
	char	*raw;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (g_mini.raw_input[i])
	{
		raw = g_mini.raw_input;
		if (raw[i] == '$' && (raw[i + 1] == ' ' || raw[i + 1] == '\0'))
			i++;
		ft_quotes(raw, &single_quotes, &double_quotes, &i);
		if (raw[i] == '$' && single_quotes == 1)
		{
			while (raw[i] != 39)
				i++;
			single_quotes = 0;
		}
		else if (raw[i] == '$' && raw[i + 1] != ' ' && raw[i + 1] != '\0')
			ft_env_vars(g_mini.raw_input);
		if (g_mini.raw_input[i])
			i++;
	}
}

/*
* helper function for ft_env_vars;
* used for checking if content is in quotes
* and what type of quotes;
* if quote found it sets flags to the opposite
* int value;
*/
void	ft_quotes(char *raw_input, int *single_quotes, \
					int *double_quotes, int *pos)
{
	if (raw_input[*pos] == 34)
	{
		if (*single_quotes == 0)
			*double_quotes = 1;
		else if (*single_quotes == 1)
			*double_quotes = -1;
		else if (*double_quotes != 0)
			*double_quotes = 0;
	}
	if (raw_input[*pos] == 39)
	{
		if (*double_quotes == 0)
			*single_quotes = 1;
		else if (*double_quotes == 1)
			*single_quotes = -1;
		else if (*double_quotes == -1)
			*single_quotes = 0;
	}
}

/*
* helper function to comply with norminette;
*/
void	ft_check_doll_help_2(char *raw_input, int pos)
{
	if (raw_input[pos - 1] == 39 && raw_input[pos - 2] == 34)
		ft_put_env_in_input(raw_input, pos);
	else if (raw_input[pos - 1] != 39)
		ft_put_env_in_input(raw_input, pos);
}
