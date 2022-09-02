/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42Seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 18:57:19 by seoykim           #+#    #+#             */
/*   Updated: 2020/10/20 18:57:37 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define FD_MAX 10241
# define SUCCESS 1
# define FAIL 0
# define ERROR -1

int		get_next_line(int fd, char **line);

char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	str_nulset(char *str, int size);
#endif
