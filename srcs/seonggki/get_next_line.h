/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonggki <seonggki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:18:23 by seonggki          #+#    #+#             */
/*   Updated: 2020/11/03 17:30:08 by seonggki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);

#endif
