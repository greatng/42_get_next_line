/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:46 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/29 15:00:20 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_read
{
	char	*content;
	size_t	pos;
}	t_read;

char	*get_next_line(int fd);
char	*ft_strnjoin(char const *s1, char const *s2, size_t s2_len);
int		ft_findchr(const char *s, int c);
size_t	ft_strlen(char const *s);

#endif