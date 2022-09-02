/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:50:48 by mihykim           #+#    #+#             */
/*   Updated: 2020/07/19 06:46:17 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** - Read the text available on a file descriptor, one line without newline.
** - Read file only once.
** - Do not read whole file and then process each line.
** - Try to read as little as possible each time get_next_line is called.
*/

static int	handle_line(char **line, char **note, char *nl_here)
{
	char	*tmp;

	if (nl_here != NULL)
	{
		*line = ft_strndup(*note, nl_here - *note);
		tmp = ft_strndup(nl_here + 1, ft_strlen(nl_here + 1));
		free(*note);
		*note = tmp;
		return (NL);
	}
	if (*note != NULL)
	{
		*line = *note;
		*note = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (_EOF);
}

int			get_next_line(int fd, char **line)
{
	static char	*note[OPEN_MAX];
	static char	buff[BUFFER_SIZE + 1];
	int			byte;
	char		*tmp;
	char		*nl_here;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (ERROR);
// 열린 파일이 없거나 파일 내용이 없거나 컴파일 시 지정한 버퍼사이즈가 0이하면 에러를 리턴한다.
// 여기에서 에러는 -1
	while ((nl_here = ft_strchr(note[fd], '\n')) == 0
			&& (byte = read(fd, buff, BUFFER_SIZE)) > 0)
// nl_here에 note에서 불러온 개행문자의 '위치'를 찾아서 집어넣는다. (개행문자가 없다면 널 반환)
// byte에 읽어온 바이트 수를 저장하며(read함수의 반환값)
// 동시에 read함수를 통해 파일의 앞부터 BUFFER_SIZE 만큼 받아 buff 어레이에 저장한다.
// note[fd]에 개행문자가 없으면서 buff에 저장한 바이트 수가 0 초과인 한 반복문을 계속 돌린다.
	{
		buff[byte] = 0;
		tmp = note[fd] == NULL ? ft_strndup(buff, byte) :
			ft_strjoin(note[fd], buff);
			// note[fd]가 널이면 tmp는 ft_strndup(buff, byte)
			// ft_strndup()는 buff를 byte만큼만 메모리에 복사하고, 메모리 위치(포인터)반환
			// 널이 아니라면 tmp는 ft_strjoin(note[fd], buff)
			// ft_strjoin()는 문자열 두개를 합쳐서 반환하는 함수
			// 고로 널이 아니라면 원래 있던 내용 뒤에 buff를 붙인게 tmp가 됨
		if (note[fd] != 0)
			free(note[fd]);
		note[fd] = tmp;
		//note[fd]에 tmp값을 넣는다
	}
	if (byte < 0)
		return (ERROR);
	return (handle_line(line, &note[fd], nl_here));
	//handle_line(line, )
}
