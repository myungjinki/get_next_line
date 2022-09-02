/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woojkim <woojkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:43:54 by woojkim           #+#    #+#             */
/*   Updated: 2020/11/21 20:40:23 by woojkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char			*combine_str(char *s1, char *s2);
int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
char			*ft_strdup(char *str);
int				find_newline(char *str);
int				check_newline(char *str);
char			*rtn_line(char *src, int idx);
char			*rtn_str(char *src, int idx);

#endif
