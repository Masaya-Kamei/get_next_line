/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:17:43 by mkamei            #+#    #+#             */
/*   Updated: 2020/10/26 13:21:07 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (char *)(s + i);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (char *)(s + i);
	return (NULL);
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

	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
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

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char	*sub;

	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(sub, s1 + start, len + 1);
	return (sub);
}
