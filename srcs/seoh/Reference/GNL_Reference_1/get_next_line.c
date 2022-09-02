/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:56:35 by hycho             #+#    #+#             */
/*   Updated: 2020/10/25 06:11:13 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_input_slot(char *slot, char *buff)
{
	char	*tmp;

	if (slot)
	{
		tmp = ft_strjoin(slot, buff);
		free(slot);
		slot = ft_strdup(tmp);
		free(tmp);
	}
	else
		slot = ft_strdup(buff);
	return (slot);
}

char	*ft_clrline(char *slot, char **line, int byte)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (slot[i])
	{
		if (slot[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(slot))
	{
		*line = ft_substr(slot, 0, i);
		tmp = ft_substr(slot, i + 1, ft_strlen(slot));
		free(slot);
		slot = ft_strdup(tmp);
		free(tmp);
	}
	else if (byte == 0)
	{
		*line = slot;
		slot = NULL;
	}
	return (slot);
}

int		get_next_line(int fd, char **line)
{
	static char	*slot[4096];
	char		buff[BUFFER_SIZE + 1];
	int			byte;

	while ((byte = read(fd, buff, BUFFER_SIZE)))
	{
		if (byte == -1)
			return (-1);
		buff[byte] = '\0';
		slot[fd] = ft_input_slot(slot[fd], buff);
		if (ft_strrchr(buff, '\n'))
			break ;
	}
	if (byte <= 0 && !slot[fd])
	{
		*line = ft_strdup("");
		return (byte);
	}
	slot[fd] = ft_clrline(slot[fd], line, byte);
	if (byte <= 0 && !slot[fd])
		return (byte);
	return (1);
}
