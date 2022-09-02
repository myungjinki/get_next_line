/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:02:14 by seoh              #+#    #+#             */
/*   Updated: 2020/07/19 12:44:26 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** - GNL 함수를 loop 안에서 호출하면 fd의 텍스트를 EOF가 올 때 까지 한 번에 한 줄씩 읽을 수 있다.
** - GNL 함수를 처음 호출 했을 때 파일을 끝까지 읽었다 하더라도, 두 번째 호출했을 때는 두 번째 line부터 시작해야한다.
** - file로부터, redirection으로부터, stdin으로부터 읽었을 때 함수가 제대로 동작해야 함
** - BUFFER_SIZE가 1일 때도, 9999일 때도, 10000000 (1000만)일 때도 제대로 동작해야 함
*/

void	jool(char **line, char **str, char *newline, int fd)
{
	*line = ft_substr(str[fd], 0, newline - str[fd]);
	str[fd] = ft_strdup(newline + 1);
}

int		get_next_line(int fd, char **line)
{
	static char *str[4096];
	char		buf[BUFFER_SIZE + 3];
	char		*temp;
	char		*newline;
	int			nread;

	nread = 1;
	while ((newline = ft_strchr(str[fd], '\n')) == 0 && nread != 0)
	{
		if ((nread = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[nread] = '\0';
		temp = str[fd] == NULL ? ft_strdup(buf) : ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = temp;
	}
	if (newline != NULL && (temp = str[fd]))
	{
		jool(line, str, newline, fd);
		free(temp);
		return (1);
	}
	*line = str[fd];
	str[fd] = NULL;
	return (0);
}
