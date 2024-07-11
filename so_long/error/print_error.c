#include "../so_long.h"

void    print_error(char *status)
{
    int len;

    len = ft_strlen(status);
    write(2, status, len);
}