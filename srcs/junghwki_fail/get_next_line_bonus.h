#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7 
# endif
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize); 
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
#endif