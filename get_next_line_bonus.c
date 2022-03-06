/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:46:43 by pngamcha          #+#    #+#             */
/*   Updated: 2022/03/06 21:59:58 by pngamcha         ###   ########.fr       */
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
			content = ft_strjoin_f(content, buff, read_size);
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
	static t_read	result[50000];
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 50000)
		return (0);
	result[fd].content = get_read(fd, result[fd].content);
	if (result[fd].content)
	{
		line = get_line(result[fd].content, &result[fd].pos);
		if (!line)
			free (result[fd].content);
		return (line);
	}
	else
		return (0);
}

/*
int     main(void)
{
    int     fd;
    char    *ret;
	int n = 0;

    if ((fd = open("./gnlTester/files/42_with_nl", O_RDONLY)) < 3 && fd != 0)
        return (-1);
    while (n != 40)
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
