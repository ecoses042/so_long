#include "../so_long.h"

void ft_free_Map_Info(t_MapInfo *Map)
{
    int i;

    i = Map->height - 1;
    if (!Map)
        return ;
    while (++i <= Map->height)
        free(Map->map[i]);
    free(Map->map);
    if (!Map->check_path)
        return ;
    i = Map->height - 1;
    while (++i <= Map->height)
        free(Map->check_path[i]);
    free(Map->check_path);
}
#include <stdio.h>
void ft_free_queue(t_queue *q)
{
    int placeholder1;
    int placeholder2;

    placeholder1 = 0;
    placeholder2 = 0;
    if (!q)
        return ;
    while (!queue_isEmpty(q))
    {
        dequeue(q, &placeholder1, &placeholder2);
    }
}