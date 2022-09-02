/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 22:04:06 by seoh              #+#    #+#             */
/*   Updated: 2020/07/19 12:44:25 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4095

# endif
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, unsigned int start, int len);
char	*ft_strdup(char *str);
int		get_next_line(int fd, char **line);

#endif
