/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:41:14 by mki               #+#    #+#             */
/*   Updated: 2020/11/30 20:59:22 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;

	if (!s1)
		return (NULL);
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	if (!(ret = (char *)malloc(len_s1++ + len_s2++ + 1)))
		return (NULL);
	index = 0;
	while (--len_s1)
		ret[index++] = *(s1++);
	while (--len_s2)
		ret[index++] = *(s2++);
	ret[index] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*tmp;
	size_t	len;

	len = 0;
	while (s1[len])
		len++;
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	tmp = ret;
	while (*s1)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (ret);
}

char	*find_line(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (NULL);
}
