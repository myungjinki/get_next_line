/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojkim <woojkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:42:02 by woojkim           #+#    #+#             */
/*   Updated: 2020/11/21 20:40:19 by woojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char		*combine_str(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
	}
	free(s1);
	if (s2 != NULL)
		while (s2[j])
			new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char		*ft_strdup(char *str)
{
	char	*new;
	int		i;

	if (!(new = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int			check_newline(char *str)
{
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int			find_newline(char *str)
{
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}
