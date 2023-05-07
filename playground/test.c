#include <stdio.h>
#include "get_next_line.h"
​
int		get_next_line(int fd, char **line)
{
	static char	*isremain; // check '\n', if don't initailize, fill 0 automatically
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			reader; // read에서 얼마만큼 byte를 읽어왔는지
​
	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	if (!(isremain = malloc(sizeof(char) + 1))) // malloc(1) is also correct!
		return (-1);
	while ((readder = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		isremain = ft_strjoin(isremain, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	while (*isremain != '\n')
		*tmp++ = *isremain++;
	line = tmp;
	free(tmp);
	*isremain = '\0';
	isremain = ft_strdup(isremain + 1);
}
​
int main(void)
{
	char *line = 0;
	int result;
	int fd;
​
	fd = open("test.txt", O_RDONLY);
	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}