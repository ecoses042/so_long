#include "../so_long.h"

//open argument file and return 2-d array of char.
char **open_map(char *av)
{
    int fd;
    char *line;
    char *lines;

    line = " ";
    lines = NULL;
    fd = open(av, O_RDONLY);
    if (fd < 0)
        print_error(INVALID_FILE);
    while (line)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (!lines)
            lines = ft_strdup(line);
        else
            lines = ft_strjoin(lines, line);
        free(line);
    }
    return (ft_split(lines, '\n'));
}