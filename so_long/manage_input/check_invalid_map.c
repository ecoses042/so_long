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
    Map_array->height = i;
    return (false);
}

bool is_invalid_fence(t_MapInfo *Map_array)
{

}

bool is_invalid_goal(t_MapInfo *Map_array)
{

}
bool is_invalid_map(t_MapInfo *Map_array)
{
    if (is_invalid_fence(Map_array))
        return (true);
    if (is_invalid_goal(Map_array))
        return (true);
    if (is_invalid_shape(Map_array))
        return (true);
    //dfs search to check map
}