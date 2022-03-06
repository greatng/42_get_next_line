/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:34:13 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/06 16:06:29 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char const *s)
{
	size_t	n;

	n = 0;
	if (!s)
		return (n);
	while (s[n])
		n++;
	return (n);
}

//special strjoin with free(s1) for leaks preventation
char	*ft_strjoin_f(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[i] = '\0';
	free((char *)s1);
	return (result);
}


