/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42Seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:57:55 by seoykim           #+#    #+#             */
/*   Updated: 2020/10/21 16:20:02 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	int		slen;
	char	*newstr;

	slen = 0;
	while (s[slen])
		slen++;
	if (!(newstr = (char *)malloc(sizeof(char) * (slen + 1))))
		return (NULL);
	newstr[slen] = '\0';
	slen = -1;
	while (s[++slen])
		newstr[slen] = s[slen];
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*join;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	join = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(len1 + len2) || !join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}

void	str_nulset(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		str[i++] = '\0';
}