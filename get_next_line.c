/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:48:13 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/29 09:57:41 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pre_len;
	size_t	suf_len;
	char	*join;

	pre_len = ft_strlen(s1);
	suf_len = ft_strlen(s2);
	if (!(join = (char *)malloc((pre_len + suf_len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(join, s1, pre_len + 1);
	ft_strlcpy(join + pre_len, s2, suf_len + 1);
	return (join);
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

	if (fd < 0 || fd >= 256 || line == NULL || BUFFER_SIZE <= 0)
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
	*line = NULL;
	readsize = read_until_include_nl(fd, buf, line, &save);
	free(buf);
	free(save);
	if (readsize <= 0)
		return (readsize);
	return (create_line(line, &save));
}
