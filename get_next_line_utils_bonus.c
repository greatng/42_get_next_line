/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:46:36 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/26 17:37:03 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char const *s1, char const *s2, size_t s2_len)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	char	*result;

	s1_len = ft_strlen(s1);
	result = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

int	ft_findchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}
