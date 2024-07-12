#include "../so_long.h"


//take argument map and check the following
//check if map is rectangular
//check if map is surrounded with fences
//check if the goal exists
//check if map can be done
//if more than 1 of them is false, return true
bool is_invalid_shape(t_MapInfo *Map_array)
{
    size_t i;
    size_t current_len;
    size_t len;

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
    size_t i;
    size_t j;

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
    size_t i;
    size_t j;

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
    if (check.exit == 0 || check.score == 0 || check.start == 0 || check.start > 1)
        return (true);
    return (false);
}


#include <stdio.h>

bool is_invalid_map(t_MapInfo *Map_array)
{
    if (is_invalid_shape(Map_array))
        return (true);
    printf("shape passed\n");
    if (is_invalid_fence(Map_array))
        return (true);
    printf("fence passed\n");
    if (is_invalid_goal(Map_array))
        return (true);
    printf("goal passed\n");
    if (is_impossible_map(Map_array))
        return (true);
    printf("all test passed. file verified\n");
    return (false);
    //dfs search to check map
}