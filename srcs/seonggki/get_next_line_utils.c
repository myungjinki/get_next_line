/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:23:27 by seonggki          #+#    #+#             */
/*   Updated: 2020/11/03 15:07:21 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*tmp;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp = s3;
	while (*s1 != '\0')
		*tmp++ = *s1++;
	while (*s2 != '\0')
		*tmp++ = *s2++;
	*tmp = '\0';
	return (s3);
}
