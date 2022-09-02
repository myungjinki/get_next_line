/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42Seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:56:39 by seoykim           #+#    #+#             */
/*   Updated: 2020/10/21 16:19:56 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_line_from_stack(char **stack, char **line)
{
	int		nl;
	char	*stack_str;

	stack_str = *stack;
	if (!*stack_str)
		return (FAIL);
	nl = -1;
	while (stack_str[++nl])
		if (stack_str[nl] == '\n')
		{
			stack_str[nl] = '\0';
			*line = ft_strdup(stack_str);
			*stack = ft_strdup(&stack_str[nl + 1]);
			free(stack_str);
			stack_str = NULL;
			return (SUCCESS);
		}
	return (FAIL);
}

static int	read_file(int fd, char *buffer, char **stack, char **line)
{
	int		ret;
	char	*temp;

	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!*stack)
			*stack = ft_strdup(buffer);
		else
		{
			temp = *stack;
			*stack = ft_strjoin(temp, buffer);
			free(temp);
			temp = NULL;
		}
		if (get_line_from_stack(stack, line))
			return (SUCCESS);
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*stacks[FD_MAX];
	char		*buffer;
	int			ret;

	if (fd < 0 || fd >= FD_MAX || read(fd, &stacks[fd], 0) < 0 || !line)
		return (ERROR);
	if (stacks[fd] && get_line_from_stack(&stacks[fd], line) == SUCCESS)
		return (SUCCESS);
	if (BUFFER_SIZE <= 0 ||
			!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	str_nulset(buffer, BUFFER_SIZE + 1);
	ret = read_file(fd, buffer, &stacks[fd], line);
	free(buffer);
	if (ret < 0)
		return (ERROR);
	if (ret == 0)
	{
		*line = stacks[fd];
		if (!stacks[fd])
			*line = ft_strdup("");
		stacks[fd] = NULL;
		return (FAIL);
	}
	return (SUCCESS);
}
