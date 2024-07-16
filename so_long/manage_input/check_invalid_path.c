#include "../so_long.h"

bool find_start(t_MapInfo *Map_array,int *first, int *second)
{
    *first = 0;
    while (++(*first) <= Map_array->height)
    {
        *second = -1;
        while (++(*second) <= Map_array->width)
        {
            if (Map_array->map[*first][*second] == 'P')
                return (false);
        }
    }
    return (true);
}

bool bfs(t_MapInfo *Map, t_queue *find_exit, t_map_var *check_condition)
{
    t_queue cord;

    init_queue(&cord);
    while (!queue_isEmpty(find_exit))
    {
        dequeue(find_exit, &cord.first, &cord.second);
        check_current(Map, check_condition, cord.first, cord.second);
        enqueue_possible_cord(Map, find_exit, cord, check_condition);
    }
    ft_free_queue(find_exit);
    return (dfs_end(check_condition));
}

bool is_invalid_path(t_MapInfo *Map_array)
{
    int i;
    int j;
    t_queue find_exit;
    t_map_var check_condition;

    init_map_var(&check_condition);
    init_check_path(Map_array);
    if (find_start(Map_array,&i,&j))
    {
        print_error("cannot find the starting point\n");
        ft_free_Map_Info(Map_array);
    }
    Map_array->px = i;
    Map_array->py = j;
    init_queue(&find_exit);
    enqueue(&find_exit, i, j);
    return (bfs(Map_array, &find_exit, &check_condition));
}