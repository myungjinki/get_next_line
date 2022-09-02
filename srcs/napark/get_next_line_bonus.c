/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoko <seoko@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:22:00 by seoko             #+#    #+#             */
/*   Updated: 2021/01/15 17:00:00 by seoko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		read_ent(t_list *lst, char **line)
{
	size_t	i;
	size_t	j;
	int		status;

	i = ft_strlen(*line);
	if (!resize(line, i))
		return (-1);
	status = 0;
	j = 0;
	while (lst->buf[j])
	{
		(*line)[i] = lst->buf[j];
		if (lst->buf[j++] == '\n')
		{
			status = 1;
			break ;
		}
		i++;
	}
	(*line)[i] = 0;
	i = 0;
	while (lst->buf[j])
		lst->buf[i++] = lst->buf[j++];
	lst->buf[i] = 0;
	return (status);
}

int		read_line(int fd, char **line, t_list *lst)
{
	int	size;
	int	status;

	*line = 0;
	if ((status = read_ent(lst, line)))
		return (status);
	while ((size = read(fd, lst->buf, BUFFER_SIZE)) > 0)
	{
		lst->buf[size] = 0;
		if ((status = read_ent(lst, line)))
			return (status);
	}
	if (size == -1)
	{
		free(*line);
		*line = NULL;
	}
	return (size);
}

int		get_next_line(int fd, char **line)
{
	int				status;
	t_list			*new;
	static t_list	*buf_lst;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	new = buf_lst;
	while (new != NULL)
	{
		if (new->fd == fd)
			break ;
		new = new->next;
	}
	if (new == NULL)
	{
		if (((new = ft_lstnew(fd)) == NULL))
			return (-1);
		new->next = buf_lst;
		buf_lst = new;
	}
	status = read_line(fd, line, find_lst(fd, buf_lst));
	if (status == 0 || status == -1)
		lst_remove(fd, &buf_lst);
	return (status);
}
