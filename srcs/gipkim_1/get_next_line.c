#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    static F_LIST *openfiles;
    F_LIST *f;
    int i;

    f = openfiles;
    if (fd < 0 || BUFFER_SIZE < 0)
        return (-1);
    while (f && f->fd != fd)
        f = f->next;
    if (!(f)) //first time for read
    {
        if (fd < 0 || BUFFER_SIZE < 0 || !(f = malloc(sizeof(F_LIST))) || !(f->fd = fd) || (f->indicator = 0))
            return (-1);
        f->next = openfiles; //if openfiles's pointer is null, f->next's pointer is null too
        openfiles = f;
    }
    //finished setting
    //then read file
    i = 0;
    f->index_of_char = 0;
    if ((f->indicator % f->read_buff_size) && (f->read_buff_size))
    {
        printf("here is prebuff side.\n");
        printf("f->indicator: %d\n", f->indicator);
        printf("f->read_buff size: %zu\n", f->read_buff_size);
        i += f->read_buff_size - f->indicator;
        if (!(f->line_buff = (char*)malloc(sizeof(char) * (i + 1))))
            return (-1);
        while (f->indicator % f->read_buff_size)
        {
            printf("here is line_buff <- read_buff copy side(%c)\n", f->read_buff[f->indicator]);
            if (((f->line_buff[f->index_of_char++] = f->read_buff[f->indicator++]) == '\n') && !(f->line_buff[f->index_of_char] = '\0'))
            {
                *line = f->line_buff;
                return (1);
            }
        }
    }
    printf("here copy side\n");
    while ((f->read_buff_size = read(fd, f->read_buff, BUFFER_SIZE))) //read()에서 복사
    {
        f->indicator = 0;
        f->tmp = f->line_buff;
        printf("f->line buff: %s\n", f->line_buff);
        f->line_buff = (char*)malloc(sizeof(char) * (i + f->read_buff_size + 1));
        f->index_of_char = 0;
        printf("f->read_buff size: %zu\n", f->read_buff_size);
        while (i > 0 && (f->tmp[f->index_of_char] != '\0'))
        {
            printf("here is line_buff <- tmp copy side(%c)\n", f->tmp[f->index_of_char]);
            f->line_buff[f->index_of_char] = f->tmp[f->index_of_char];
            f->index_of_char++;
        }
        if (i > 0)
            free(f->tmp);
        while (f->indicator < f->read_buff_size)
        {
            printf("here is line_buff <- read_buff copy side(%c)\n", f->read_buff[f->indicator]);
            f->line_buff[f->index_of_char] = f->read_buff[f->indicator];
            f->indicator++;
            if (f->line_buff[f->index_of_char++] == '\n')
            {
                printf("f->indicator: %d\n", f->indicator);
                printf("end line copy~~!!\n\n");
                f->line_buff[f->index_of_char] = '\0';
                *line = f->line_buff;
                return (1);
            }
        }
        f->line_buff[f->index_of_char] = '\0';
        i += f->read_buff_size;
    }
    if (f->index_of_char)
    {
        f->line_buff[f->index_of_char] = '\0';
        *line = f->line_buff;
        return (1);
    }
    f->line_buff[f->index_of_char] = '\0';
    *line = f->line_buff;
    return (0);

}

int main(void)
{
    char **lines;
    int fd;
    int i;

    i = 0;
    lines = (char**)malloc(sizeof(char**) * 5);
    if (0 < (fd = open("./lines.txt", O_RDONLY)))
    {
        while (get_next_line(fd, &lines[i]))
        {
            printf("%s", lines[i++]);
            i++;
        }
    }


    return 0;
}