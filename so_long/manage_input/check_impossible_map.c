#include "../so_long.h"

void find_start(t_MapInfo *Map_array,int *first, int *second)
{
    first = 0;
    while (++first<= Map_array->height)
    {
        second = -1;
        while (++second <= Map_array->width)
        {
            if (Map_array->map[*first][*second] == 'P')
                return ;
        }
    }
}

void enqueue_possible_cord(t_MapInfo *Map,t_queue *find_exit, int first, int second)
{
    
}

void dfs(t_MapInfo *Map, t_queue *find_exit, t_map_var *check_condition, int *first, int *second)
{
    enqueue(find_exit, *first, *second);
    if (queue_isEmpty(find_exit))
        return ;
    
    //else, enqueue the available 
}
#include <stdio.h>
bool is_impossible_map(t_MapInfo *Map_array)
{
    int i;
    int j;
    t_queue find_exit;
    t_map_var check_condition;

    init_map_var(&check_condition);
    find_start(Map_array,&i,&j);
    dfs(&find_exit, &check_condition, i, j);
    
    //using dfs, find the way out. 
    //if the queue is empty, return flag. true if not found, false if found.
}