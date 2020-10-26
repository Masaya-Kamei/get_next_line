/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:48:13 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/26 11:57:33 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	s_len = ft_strlen(s1);
	if ((start >= s_len) || len == 0)
		return (ft_strdup(""));
	if (s_len < (start + len))
		len = s_len - start;
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(sub, s1 + start, len + 1);
	return (sub);
}

static int	create_line(char **line, char **save)
{
	char *new_line_ptr;
	char *tmp;

	new_line_ptr = ft_strchr(*line, '\n');
	if (new_line_ptr == NULL)
	{
		*save = NULL;
		return (0);
	}
	else
	{
		tmp = ft_substr(*line, 0, new_line_ptr - *line);
		*save = ft_substr(new_line_ptr + 1, 0, ft_strlen(new_line_ptr + 1));
		free(*line);
		*line = tmp;
		if (*line == NULL)
			return (-1);
		else if (*save == NULL)
		{
			free(*line);
			return (-1);
		}
		return (1);
	}
}

static int	read_until_include_nl(int fd, char *buf, char **line, char **save)
{
	ssize_t	readsize;
	char	*tmp;

	if (!(*line = ft_strdup(*save)))
		return (-1);
	if (ft_strchr(*line, '\n') != NULL)
		return (1);
	while ((readsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[readsize] = '\0';
		tmp = ft_strjoin(*line, buf);
		free(*line);
		*line = tmp;
		if (*line == NULL)
			return (-1);
		if (ft_strchr(*line, '\n') != NULL)
			return (1);
	}
	if (*line[0] == '\0' && readsize == 0)
		return (0);
	else if (readsize == 0)
		return (1);
	else
		return (-1);
}

int			get_next_line(int fd, char **line)
{
	int			readsize;
	char		*buf;
	static char *save;

	*line = NULL;
	if (fd < 0 || fd >= OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (save == NULL)
	{
		if (!(save = ft_strdup("")))
		{
			free(buf);
			return (-1);
		}
	}
	readsize = read_until_include_nl(fd, buf, line, &save);
	free(buf);
	free(save);
	if (readsize <= 0)
		return (readsize);
	return (create_line(line, &save));
}
