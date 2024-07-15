#include "../so_long.h"


//take argument map and check the following
//check if map is rectangular
//check if map is surrounded with fences
//check if the goal exists
//check if map can be done
//if more than 1 of them is false, return true
bool is_invalid_shape(t_MapInfo *Map_array)
{
    int i;
    int current_len;
    int len;

    i = 0;
    len = ft_strlen(Map_array->map[i]);
    i++;
    while(Map_array->map[i])
    {
        current_len = ft_strlen(Map_array->map[i]);
        if (current_len != len)
            return (true);
        i++;
    }
    Map_array->width = current_len - 1;
    Map_array->height = i - 1;
    return (false);
}

#include <stdio.h>
bool is_invalid_fence(t_MapInfo *Map_array)
{
    int i;
    int j;

    i = -1;
    while (++i <= Map_array->height)
    {
        j = -1;
        while (++j <= Map_array->width)
        {
            if ((i == Map_array->height || j == Map_array->width)
            && Map_array->map[i][j] != '1')
                return (true);
        }
    }
    return (false);
}

//3 things to check.
bool is_invalid_goal(t_MapInfo *Map_array)
{
    t_map_var check;
    int i;
    int j;

    i = -1;
    init_map_var(&check);
    while (++i <= Map_array->height)
    {
        j = -1;
        while (++j <= Map_array->width)
        {
            update_map_var(Map_array->map[i][j], &check);
        }
    }
    if (check.exit != 1 || check.score == 0 || check.start != 1)
        return (true);
    return (false);
}


#include <stdio.h>

bool is_invalid_map(t_MapInfo *Map_array)
{
    if (is_invalid_shape(Map_array))
        return (print_error("map shape error\n"));
    if (is_invalid_fence(Map_array))
        return (print_error("fence not found\n"));
    if (is_invalid_goal(Map_array))
        return (print_error("goal not found\n"));
    if (is_invalid_path(Map_array))
        return (print_error("path not found\n"));
    return (false);
    //dfs search to check map
}