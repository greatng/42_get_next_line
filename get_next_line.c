/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:40:27 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/06 17:57:08 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*line;

	i = *pos;
	j = 0;
	while (content[i] != '\n' && content[i])
		i++;
	line = malloc(sizeof(char) * (i - (*pos) + 2));
	if (!line)
		return (NULL);
	while (*pos < i + 1 && content[*pos])
		line[j++] = content[(*pos)++];
	line[j] = '\0';
	return (line);
}

static char	*get_read(int fd,char *content)
{
	int	read_size;
	char	*buff;

	read_size = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (read_size > 0)
	{
		read_size = read (fd, buff, BUFFER_SIZE);
		if (read_size < 0) 
			return (gnl_free(buff));
		buff[read_size] = '\0';
		if (read_size > 0)
			content = ft_strjoin_f(content, buff, read_size);
		if (buff && ft_findchr(buff, '\n'))
			break;
	}
	free(buff);
	return (content);
}

char	*get_next_line(int fd)
{
	static	t_read	result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	result.content = get_read(fd, result.content);
	if (result.content)
		return (get_line(result.content, &result.pos));
	else
		return (0);
}

/*
int     main(void)
{
    int     fd;
    char    *ret;
	int n = 0;

    if ((fd = open("get_next_line.h", O_RDONLY)) < 3 && fd != 0)
        return (-1);
    while (n != 80)
    {
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);
	n++;
    }
    close (fd);
    return (0);
}
*/