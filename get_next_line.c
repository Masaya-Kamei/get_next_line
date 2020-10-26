/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:10:44 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/25 20:33:51 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	release(char **buf, int ret, char **line)
{
	if ((ret == 0 || ret == -1 ) && *line == NULL)
		*line = ft_strdup("", 0);
	if (buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
	return (ret);
}

static int	read_fd(int fd, char *buf, char **save)
{
	int readsize;
	int	save_len;

	if (*save != NULL)
	{
		save_len = ft_strlen(*save);
		ft_strlcpy(buf, *save, save_len + 1);
		free(*save);
		*save = NULL;
		readsize = read(fd, buf + save_len, BUFFER_SIZE - save_len);

		if (readsize == -1)
			return (readsize);
		readsize += save_len;
		buf[readsize] = '\0';
	}
	else
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize == 0 || readsize == -1)
			return (readsize);
		buf[readsize] = '\0';
	}
	return (readsize);
}

static char	*ft_strjoin_free(char *buf, char **line, int valid_buf_size)
{
	size_t	pre_len;
	size_t	suf_len;
	char	*join;

	if (*line == NULL)
	{
		if (!(join = (char *)malloc((valid_buf_size + 1) * (sizeof(char)))))
			return (NULL);
		ft_strlcpy(join, buf, valid_buf_size + 1);
		return (join);
	}
	pre_len = ft_strlen(*line);
	suf_len = valid_buf_size;
	if (!(join = (char *)malloc((pre_len + suf_len + 1) * sizeof(char))))
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	ft_strlcpy(join, *line, pre_len + 1);
	ft_strlcpy(join + pre_len, buf, suf_len + 1);
	free(*line);
	*line = NULL;
	return (join);
}

static int	assign_to_line(char **line, char *buf, char **save, int readsize)
{
	int	valid_buf_size;

	valid_buf_size = ft_strchr_index(buf, '\n');
	if (!(*line = ft_strjoin_free(buf, line, valid_buf_size)))
		return (MEM_ERROR);
	if (valid_buf_size == readsize)
	{
		if (readsize < BUFFER_SIZE)
			return (NOT_NEWLINE_END);
		ft_memset(buf, '\0', BUFFER_SIZE + 1);
		return (CONTINUE_ASSIGN);
	}
	else if (valid_buf_size == (readsize - 1))
		return (END_ASSIGN);
	else
	{
		if (!(*save = ft_strdup(buf + valid_buf_size + 1, readsize - valid_buf_size)))
			return (MEM_ERROR);
		return (END_ASSIGN);
	}
}

int			get_next_line(int fd, char **line)
{
	int			readsize;
	char		*buf;
	int			f;
	static char *save = NULL;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (release(NULL, -1, line));
	while (1)
	{
		if ((readsize = read_fd(fd, buf, &save)) == -1)
			return (release(&buf, -1, line));
		else if (readsize == 0)
		{
			if (*line == NULL)
				return (release(&buf, 0, line));
			else
				break ;
		}
		if ((f = assign_to_line(line, buf, &save, readsize)) == MEM_ERROR)
			return (release(&buf, -1, line));
		else if (f == END_ASSIGN)
			break ;
		else if (f == NOT_NEWLINE_END)
			return (release(&buf, 0, line));
	}
	return (release(&buf, 1, line));
}
