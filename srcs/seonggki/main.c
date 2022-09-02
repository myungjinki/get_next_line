/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 01:39:03 by mki               #+#    #+#             */
/*   Updated: 2020/10/24 21:35:23 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("test", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line: %s\n", line);
		printf("return value: %d\n", ret);
		free(line);
	}
	printf("get_next_line: %s\n", line);
	printf("return value: %d\n", ret);
	free(line);
	return (0);
}
