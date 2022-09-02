/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:24 by seonggki          #+#    #+#             */
/*   Updated: 2020/11/04 11:53:21 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int			ft_null(char **stack, char **line)
{
	char			*temp;
	char			*strchr_check;
	int				i;

	i = 0;
	strchr_check = *stack;
	while (strchr_check[i] != '\n')
		if (!strchr_check[i++])
			return (0);
	temp = &strchr_check[i];
	*temp = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(temp + 1);
	return (1);
}

static	int			gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int				readcnt;
	char			*tmp;

	while ((readcnt = read(fd, heap, BUFFER_SIZE)) > 0)
	{
		heap[readcnt] = '\0';
		if (*stack)
		{
			tmp = *stack;
			*stack = ft_strjoin(tmp, heap);
			free(tmp);
		}
		else
			*stack = ft_strdup(heap);
		if (ft_null(stack, line))
			break ;
	}
	return (readcnt > 0 ? 1 : readcnt);
}

int					get_next_line(int fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*heap;
	int				readcnt;
	int				i;

	if (!line || (fd < 0 || fd > MAX_FD || (read(fd, stack[fd], 0) < 0))
	|| !(heap = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (ft_null(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFFER_SIZE)
		heap[i++] = '\0';
	readcnt = gnl_read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (readcnt != 0 || stack[fd] == '\0' || stack[fd][0] == '\0')
	{
		if (!readcnt && *line)
			*line = ft_strdup("");
		return (readcnt);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (0);
}
