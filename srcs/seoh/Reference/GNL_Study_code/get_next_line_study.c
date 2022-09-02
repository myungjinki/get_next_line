/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_study.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 01:15:33 by seoh              #+#    #+#             */
/*   Updated: 2020/07/19 08:54:26 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (0);
	while (*str != c)
	{
		if (!*str)
			return (0);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	char	*ptr;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	while (*s1)
		ptr[idx++] = *s1++;
	while (*s2)
		ptr[idx++] = *s2++;
	ptr[idx] = '\0';
	return (ptr);
}

char	*ft_substr(char *str, unsigned start, int len)
{
	char	*ptr;
	int		idx;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (idx < len)
		ptr[idx++] = str[start++];
	ptr[idx] = '\0';
	return (ptr);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		idx;

	idx = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (0);
	while (*str)
		ptr[idx++] = *str++;
	ptr[idx] = '\0';
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char *str[4096];
	char	buf[BUFFER_SIZE];
	char	*temp;
	char	*newline;
	int		nread;

	nread = 1;
	while (((newline = ft_strchr(str[fd], '\n')) == NULL) && nread != 0)
	{
		if ((nread = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[nread] = '\0';
		temp = str[fd] == NULL ? ft_strdup(buf) : ft_strjoin(str[fd], buf);
		if (str[fd] != NULL)
			free(str[fd]);
		str[fd] = temp;
	}
	if (newline != NULL)
	{
		temp = str[fd];
		*line = ft_substr(str[fd], 0, newline - str[fd]);
		str[fd] = ft_strdup(newline + 1);
		free(temp);
		return (1);
	}
	*line = str[fd];
	str[fd] = NULL;
	return (0);
}

int		main(void)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("test", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line : %s\n", line);
		printf("return value : %d\n\n", ret);
		free(line);
	}
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	return (0);
}
