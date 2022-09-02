/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:22:45 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/02 16:52:27 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char *p = s;

	if (!s)
		return (0);
	while (*s)
		s++;
	return (s - p);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*dup;

	len = ft_strlen(s1) + 1;
	dup = malloc(len);
	if (dup)
	{
		ft_memcpy(dup, s1, len);
	}
	return (dup);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char		*s = src;
	unsigned char			*d;

	if (dst == NULL || src == NULL)
		return (NULL);
	d = dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*gnl_join(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dup;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (s1 ? ft_strdup(s1) : ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((dup = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
	{
		ft_memcpy(dup, s1, len1);
		free(s1);
		ft_memcpy(dup + len1, s2, len2);
		dup[len1 + len2] = 0;
	}
	return (dup);
}
