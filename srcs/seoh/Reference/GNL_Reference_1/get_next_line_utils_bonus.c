/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hycho <hycho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 21:15:08 by hycho             #+#    #+#             */
/*   Updated: 2020/05/21 22:33:42 by hycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!(s1 && s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (0);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;
	size_t	i;

	if (!(s))
		return (NULL);
	len_s = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && i + start < len_s)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*res;

	str = (char *)s;
	res = 0;
	while (1)
	{
		if (*str == c)
			res = str;
		if (*str++ == 0)
			break ;
	}
	return (res);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			cnt;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	cnt = 0;
	while (cnt++ < n)
	{
		*dest = *source;
		dest++;
		source++;
	}
	return (dst);
}
