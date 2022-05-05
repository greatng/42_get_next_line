/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:40:27 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/05 10:25:22 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*gnl_free(char *buff)
{
	if (buff)
		free(buff);
	return (NULL);
}

static char	*get_line(char *content, size_t *pos)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*line;

	i = *pos;
	j = 0;
	if (content[i] == '\0')
		return (0);
	while (content[i] != '\n' && content[i])
		i++;
	size = i - (*pos);
	if (content[i] == '\n')
		size++;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	while (*pos < i + 1 && content[*pos])
		line[j++] = content[(*pos)++];
	line[j] = '\0';
	return (line);
}

static	char	*get_read(int fd, char *content)
{
	int		read_size;
	char	*buff;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	read_size = read (fd, buff, BUFFER_SIZE);
	if (read_size < 0)
		return (gnl_free(buff));
	while (read_size > 0)
	{	
		if (read_size != 0)
		{
			buff[read_size] = '\0';
			tmp = ft_strnjoin(content, buff, read_size);
			free(content);
			content = tmp;
		}
		if ((read_size && ft_findchr(buff, '\n')))
			break ;
		read_size = read (fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (content);
}

char	*get_next_line(int fd)
{
	static t_read	result;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	result.content = get_read(fd, result.content);
	if (result.content)
	{
		line = get_line(result.content, &result.pos);
		if (!line)
		{
			free (result.content);
			result.content = NULL;
		}
		return (line);
	}
	else
		return (0);
}

// int     main(void)
// {
// 	int     fd;
// 	char    *ret;
// 	int n = 0;

//    	if ((fd = open("get_next_line.c", O_RDONLY, 0755)) < 3 && fd != 0)
//         	return (-1);
// 	while (n != 200)
// 	{
// 		ret = get_next_line(fd);
// 		write(STDOUT_FILENO, ret, ft_strlen(ret));
// 		if (ret)
// 			free(ret);
// 		n++;
// 	}
// 	close (0);
// 	close (fd);
// 	return (0);
// }
