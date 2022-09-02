/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoko <seoko@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:22:33 by seoko             #+#    #+#             */
/*   Updated: 2021/01/15 16:58:44 by seoko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int				fd;
	char			*buf;
	struct s_list	*next;
}				t_list;

void			ft_lstsize(int fd, t_list *lst);
void			lst_remove(int fd, t_list **buf_lst);
int				get_next_line(int fd, char **line);
int				resize(char **line, size_t len);
size_t			ft_strlen(char *str);
t_list			*ft_lstnew(int fd);
t_list			*find_lst(int fd, t_list *buf_lst);

#endif
