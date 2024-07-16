#include "so_long.h"
/*int main(int ac, char **av)
{
    if (check_input_error(ac, &av))
        return (1);
    return (0);
}*/


//print error when map is not there
//print error if map cannot be done

int main(int ac, char **av) 
{
    t_MapInfo Map_array;

    if (ac < 2)
        return (1);
    if (is_invalid_file(av[1]))
        return (print_error(INVALID_FILE));
    Map_array.map = open_map(av[1]);
    if (is_invalid_map(&Map_array))
    {
        ft_free_Map_Info(&Map_array);
        return (print_error(INVALID_MAP));
    }
    print_error("valid map indeed\n");
    manage_window(&Map_array);
    ft_free_Map_Info(&Map_array);
    return (0);
}