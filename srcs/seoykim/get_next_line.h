/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42Seoul.f>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:50:20 by seoykim           #+#    #+#             */
/*   Updated: 2020/10/20 17:08:56 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
