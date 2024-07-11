#include "so_long.h"
/*int main(int ac, char **av)
{
    if (check_input_error(ac, &av))
        return (1);
    return (0);
}*/


//print error when map is not there
//print error if map cannot be done

#include <stdio.h>

int main(int ac, char **av) 
{
    t_MapInfo *Map_array;

    if (ac < 2)
        return (1);
    if (is_invalid_file(av[1]))
        printf("error\n");
    Map_array->map = open_map(av[1]);
    /*if (is_invalid_map(Map_array))
    {

    }*/
    return (0);
}