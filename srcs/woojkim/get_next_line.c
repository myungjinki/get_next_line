/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojkim <woojkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:44:46 by woojkim           #+#    #+#             */
/*   Updated: 2020/11/27 19:21:01 by woojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*rtn_line(char *src, int idx)
{
	char		*new;
	int			i;

	if (!(new = malloc(sizeof(char) * (idx + 1))))
		return (NULL);
	if (src == NULL)
	{
		new[0] = '\0';
		return (new);
	}
	i = 0;
	while (src[i] && i < idx && src[i] != '\n')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			*rtn_str(char *src, int idx)
{
	char		*new;
	int			i;

	i = 0;
	if (src[idx] == '\n')
		idx++;
	if (!(new = malloc(sizeof(char) * (ft_strlen(src) - idx + 1))))
		return (NULL);
	while (src[idx])
		new[i++] = src[idx++];
	new[i] = '\0';
	free((void *)src);
	return (new);
}

int				get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			rs;
	int			newline_idx;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((rs = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rs] = '\0';
		if (check_newline((str = combine_str(str, buf))))
			break ;
	}
	if (rs == -1)
		return (-1);
	if (check_newline(str) && ((newline_idx = find_newline(str)) >= 0))
	{
		*line = rtn_line(str, newline_idx);
		str = rtn_str(str, newline_idx);
		return (1);
	}
	*line = rtn_line(str, find_newline(str));
	free(str);
	str = 0;
	return (0);
}
