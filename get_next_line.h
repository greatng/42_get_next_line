/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:41:46 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/06 15:54:21 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_read
{
	char	*content;
	size_t	pos;
}	t_read;

char	*get_next_line(int fd);
char	*ft_strjoin_f(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif