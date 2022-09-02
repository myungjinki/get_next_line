/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoko <seoko@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:23:11 by seoko             #+#    #+#             */
/*   Updated: 2021/01/15 16:13:32 by seoko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstnew(int fd)
{
	t_list *lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!lst->buf)
	{
		free(lst);
		return (NULL);
	}
	lst->buf[0] = 0;
	lst->fd = fd;
	lst->next = NULL;
	return (lst);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		resize(char **line, size_t len)
{
	char	*new_line;
	size_t	i;

	new_line = (char*)malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
	if (!new_line)
		return (0);
	i = 0;
	while (i < len)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	new_line[i] = 0;
	free(*line);
	*line = new_line;
	return (1);
}

t_list	*find_lst(int fd, t_list *buf)
{
	t_list *found;

	found = buf;
	while (found->fd != fd)
		found = found->next;
	return (found);
}

void	lst_remove(int fd, t_list **buf_list)
{
	t_list	*prev;
	t_list	*rmv;
	t_list	*tmp;

	prev = *buf_list;
	if (prev->fd == fd)
	{
		tmp = prev->next;
		free(prev->buf);
		free(prev);
		*buf_list = tmp;
		return ;
	}
	while (prev->next->fd != fd)
		prev = prev->next;
	rmv = find_lst(fd, *buf_list);
	prev->next = rmv->next;
	free(rmv->buf);
	free(rmv);
}
