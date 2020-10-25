/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:14:04 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/24 22:01:42 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define MEM_ERROR -1
# define END_ASSIGN 0
# define CONTINUE_ASSIGN 1

int		get_next_line(int fd, char **line);
void	*ft_memset(void *buf, int ch, size_t n);
int		ft_strchr_index(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s, int s_len);

#endif
