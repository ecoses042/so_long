#include "../so_long.h"

bool    print_error(char *status)
{
    int len;

    len = ft_strlen(status);
    write(2, status, len);
    return (1);
}