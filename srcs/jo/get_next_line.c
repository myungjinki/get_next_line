/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:04:57 by marvin            #+#    #+#             */
/*   Updated: 2021/01/28 23:54:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		split_line(char **backup, char **line, int cnt)
{
	char	*temp;

	(*backup)[cnt] = '\0';
	*line = ft_strdup(*backup);
	if (ft_strlen(*backup + cnt + 1) == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + cnt + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int		is_newline(const char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		str_return(char **backup, char **line)
{
	int	cut_idx;

	if (*backup && (cut_idx = is_newline(*backup)) >= 0)
		return (split_line(backup, line, cut_idx));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static	char	*backup[_POSIX_OPEN_MAX];
	int				cnt;
	int				size;
	char			buf[BUFFER_SIZE + 1];

	if ((fd < 0) || (line == 0) || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((cnt = is_newline(backup[fd])) >= 0)
			return (split_line(&backup[fd], line, cnt));
	}
	return (size < 0 ? -1 : str_return(&backup[fd], line));
}
