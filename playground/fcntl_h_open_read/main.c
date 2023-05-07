/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 05:16:57 by mki               #+#    #+#             */
/*   Updated: 2020/10/19 17:17:04 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1000

int		main(void)
{
	int		read_byte;
	char	*buf;

	if((read_byte = read(open("text", O_RDONLY), buf, BUFFER_SIZE)) < 0)
		return (0);
	buf[read_byte] = '\0';
	printf("%d, %s\n", read_byte, buf);
	return (0);
}