/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:12:01 by gipkim            #+#    #+#             */
/*   Updated: 2021/01/19 19:06:43 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

F_LIST *new_fd(F_LIST *files, int fd)
{
	F_LIST *tmp;

	tmp = (F_LIST*)malloc(sizeof(F_LIST) * 1);
	tmp->fd = fd;
	tmp->indicator = 0;
	tmp->next = NULL;
	if (files)
	{
		while (files->next)
			files = files->next;
		files->next = &tmp;
		files = files->next;
	}
	return (tmp);
}

int line_append(F_LIST *f)
{
	int i;
	int j;

	i = 0;
	while (f->tmp[i])
	{
		f->line_buff[i] = f->tmp[i];
		i++;
	}
	j = 0;
	while (j < f->read_buff_size)
	{
		if (f->index_of_char++ > f->indicator)
		{
			f->line_buff[i++] = f->read_buff[j];
			if (f->read_buff[j] == '\n')
			{
				f->indicator = f->index_of_char;
				f->line_buff[i++] = '\0';
				return (1);
			}
		}
		j++;
	}
	f->indicator = f->index_of_char;
	f->line_buff[i] = '\0';
	return (0);
}
