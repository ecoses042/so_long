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

#include <stdio.h>
bool is_impossible_map(t_MapInfo *Map_array)
{
    int i;
    int j;
    t_queue find_exit;

    find_start(Map_array,&i,&j);
    enqueue(&find_exit, i,j);
    while (queue_isEmpty(&find_exit))
    {

    }
    //using dfs, find the way out. 
    //if the queue is empty, return flag. true if not found, false if found.
}