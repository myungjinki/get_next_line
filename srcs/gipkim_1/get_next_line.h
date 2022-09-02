#include <unistd.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct f_list
{
    int fd;
    char *line_buff;
    char *tmp;
    char read_buff[BUFFER_SIZE];
    size_t read_buff_size;
    int indicator;
    int i;
    int index_of_char;
    struct f_list *next;
} F_LIST;

int get_next_line(int fd, char **line);

F_LIST* new_fd(F_LIST *files, int fd);

int pre_line_append(char *line_buff, char *tmp);

int line_append(F_LIST *f);