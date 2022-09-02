/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsohn <dsohn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:22:21 by dsohn             #+#    #+#             */
/*   Updated: 2020/10/02 16:35:24 by dsohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	isline(char *str)
{
	char *temp;

	if (!str)
		return (-1);
	temp = str;
	while (*str)
	{
		if (*str == '\n')
			return (str - temp);
		str++;
	}
	return (-1);
}

static int	get_line(char **buf, int nline, char **line)
{
	char	*temp;
	int		len;

	if (!(*line = (char*)malloc(sizeof(char) * (nline + 1))))
		return (-1);
	temp = NULL;
	ft_memcpy(*line, *buf, nline);
	(*line)[nline] = 0;
	len = ft_strlen(*buf + nline + 1);
	if (len > 0)
	{
		if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
			return (-1);
		ft_memcpy(temp, *buf + nline + 1, len);
		temp[len] = 0;
	}
	free(*buf);
	*buf = temp;
	return (1);
}

static int	return_left(int rlen, char **buf, char **line)
{
	int len;

	if (rlen < 0)
		return (-1);
	if ((len = isline(*buf)) >= 0)
		return (get_line(buf, len, line));
	else if (*buf)
	{
		*line = *buf;
		*buf = NULL;
		return (0);
	}
	if (!(*line = (char*)malloc(sizeof(char))))
		return (-1);
	(*line)[0] = 0;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*save[OPEN_MAX] = { NULL, };
	char			buf[BUFFER_SIZE + 1];
	int				rlen;

	if (fd < 0 || OPEN_MAX < fd || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((rlen = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rlen] = 0;
		save[fd] = gnl_join(save[fd], buf);
		if ((rlen = isline(save[fd])) >= 0)
			return (get_line(&save[fd], rlen, line));
	}
	return (return_left(rlen, &save[fd], line));
}
