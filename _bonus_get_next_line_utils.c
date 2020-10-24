/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_get_next_line_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:28:20 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/24 18:05:38 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
		((unsigned char *)buf)[i++] = (unsigned char)ch;
	return (buf);
}

int		ft_strchr_index(const char *s, int c, int readsize)
{
	int i;

	i = 0;
	while (i < readsize)
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	if (!(copy = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(copy, s, len + 1);
	return (copy);
}
