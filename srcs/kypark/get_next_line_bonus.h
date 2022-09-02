/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:01:34 by kypark            #+#    #+#             */
/*   Updated: 2021/01/20 22:03:51 by kypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 4096

int			get_next_line(int fd, char **line);
char		*ft_strncpy(char *dst, char *src, size_t len);
char		*ft_strdup(char *s1);
int			is_nl(char *s);
size_t		line_len(char *str);
size_t		buff_len(char *str);

#endif
