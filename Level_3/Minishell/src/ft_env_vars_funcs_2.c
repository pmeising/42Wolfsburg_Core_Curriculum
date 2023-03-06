/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_vars_funcs_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:09:49 by pmeising          #+#    #+#             */
/*   Updated: 2022/11/29 15:16:26 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
* shifts content of the user input string x-chars
* to the left, so that we delete $(USER) in the string;
*/
char	*ft_replace_str(char *raw_input, int pos)
{
	int		k;
	int		len;
	int		len_compl;
	int		leni;

	k = pos;
	len = 0;
	len_compl = ft_strlen(raw_input);
	while (raw_input[k] != ' ' && raw_input[k])
	{
		len++;
		k++;
	}
	if (!raw_input[k])
		raw_input[pos] = '\0';
	if (raw_input[k])
	{
		len++;
		leni = len_compl - len;
		k = pos;
		while (raw_input[leni])
			raw_input[k++] = raw_input[leni++];
		raw_input[k] = '\0';
	}
	return (raw_input);
}

/*
* acquires USER from $(USER) which is needed
* for printing the error message correctly;
*/
void	ft_get_str(char *raw_input, int pos)
{
	char	*str;
	int		t;
	int		j;

	t = pos + 2;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(raw_input));
	while (raw_input[t] != ')' && raw_input[t])
	{
		str[j] = raw_input[t];
		j++;
		t++;
	}
	str[j] = '\0';
	if (str)
	{
		printf("bash: %s: command not found\n", str);
		free(str);
		str = NULL;
	}
}

/*
* helper to get check_doll below 25 lines;
*/
void	ft_check_doll_help(char *raw_input, int pos)
{
	int	j;

	j = pos;
	pos = pos + 1;
	while (raw_input[pos])
		g_mini.raw_input[j++] = raw_input[pos++];
	g_mini.raw_input[j] = '\0';
}

/*
	Checks for the exact sequence following the '$'
*/
char	*ft_check_doll(char *raw_input, int *pos)
{
	if (raw_input[*pos] == '$' && raw_input[*pos + 1] == '?')
	{
		ft_replace_dollar_question_mark(raw_input, *pos);
		return (NULL);
	}
	else if (raw_input[*pos] == '$' && raw_input[*pos + 1] != '(' && \
			(raw_input[*pos + 1] == '{' || \
			ft_isalnum(raw_input[*pos + 1]) == 1))
	{
		ft_check_doll_help_2(raw_input, *pos);
		return (NULL);
	}
	else if (raw_input[*pos] == '$' && raw_input[*pos + 1] == '(' )
	{
		ft_dumdum(raw_input, *pos);
		return (NULL);
	}
	else if (raw_input[*pos] == '$')
	{
		ft_check_doll_help(raw_input, *pos);
		return (NULL);
	}
	return ("HI");
}

/*
*	Receives the Variable name and loops through the 2D array of strings of
*	ENV finding the variable name. Uses ft_strnstr.
*	Return: Takes out its content and returns it to the calling function.
*	In case of an empty variable, returns NULL.
*	2nd if checks, wether the env variable is empty or not
*	by comparing the string lengths
*/
char	*ft_extract_content(char *var_name)
{
	int		var_name_len;
	int		content_len;
	char	*content;
	char	*var_name_and_content;
	t_list	*iterator;

	iterator = g_mini.dup_env;
	var_name_len = ft_strlen(var_name);
	while (iterator != NULL)
	{
		var_name_and_content = iterator->content;
		if (ft_strnstr(iterator->content, var_name, var_name_len) != NULL)
			break ;
		iterator = iterator->next;
	}
	if (iterator == NULL)
		return (NULL);
	if (ft_strlen(var_name_and_content) == (size_t)(var_name_len + 1))
		return (NULL);
	content_len = ft_strlen(&var_name_and_content[var_name_len + 1]);
	content = ft_substr(var_name_and_content, var_name_len + 1, content_len);
	return (content);
}
