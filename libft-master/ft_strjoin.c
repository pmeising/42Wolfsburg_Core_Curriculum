/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeising <pmeising@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:01:55 by pmeising          #+#    #+#             */
/*   Updated: 2022/05/18 13:23:54 by pmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	int		s1_len;
// 	int		s2_len;
// 	char	*joined;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	joined = malloc(1 * (s1_len + s2_len +1));
// 	i = 0;
// 	j = 0;
// 	while (s1[i] != '\0')
// 	{
// 		joined[i] = s1[i];
// 		i++;
// 	}
// 	while (j <= s2_len)
// 	{
// 		joined[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	return (joined);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		k;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dest = (char *)malloc(len);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		dest[i + k] = s2[k];
		k++;
	}
	dest[i + k] = '\0';
	return (dest);
}
