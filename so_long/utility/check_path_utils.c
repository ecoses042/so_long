#include "../so_long.h"

//true if conditions are not met.
//false if conditions are met
bool dfs_end(t_map_var *param)
{
    return (!param->exit && !param->score);
}

bool check_current(t_MapInfo *Map, t_map_var *check_condition, int i, int j)
{
    if (Map->check_path[i][j] != '1')
    {
        if (Map->map[i][j] == 'C')
            check_condition->score += 1;
        else if (Map->map[i][j] == 'P')
            check_condition->start += 1;
        else if (Map->map[i][j] == 'E')
            check_condition->exit += 1;
        Map->check_path[i][j] = '1';
        return (false);
    }
    return (true);
}

void init_check_path(t_MapInfo *Map)
{
    int i;
    int j;

    i = -1;
    Map->check_path = malloc(sizeof(char *) * (Map->height + 1));
    if (!Map->check_path)
        return ;
    while (++i <= Map->height + 1)
    {
        j = -1;
        Map->check_path[i] = malloc(sizeof(char *) * (Map->width + 1));
        if (!Map->check_path[i] )
            return ;
        while (++j <= Map->width + 1)
        {
            Map->check_path[i][j] = 0;
        }
    }
}

bool is_outside(t_MapInfo *Map, int x, int y)
{
    int height;
    int width;

    height = Map->height;
    width = Map->width;
    if (!(x <= height && x > 0) && !(y <= width && y > 0))
        return (true);
    return (Map->map[x][y] == '1');
}

bool is_checked(t_MapInfo *Map, int x, int y)
{
    return (Map->check_path[x][y] == '1' || Map->map[x][y] == '1');
}

void enqueue_possible_cord(t_MapInfo *Map,t_queue *find_exit, t_queue cord, t_map_var *condition)
{
    int change_first;
    int change_second;
    t_queue change_cord;

    init_queue(&change_cord);
    enqueue(&change_cord, -1, 0);
    enqueue(&change_cord, 1, 0);
    enqueue(&change_cord, 0, -1);
    enqueue(&change_cord, 0, 1);
    while (!queue_isEmpty(&change_cord))
    {
        dequeue(&change_cord, &change_first, &change_second);
        change_first += cord.first;
        change_second += cord.second;
        if (!is_outside(Map, change_first, change_second) 
        && !check_current(Map, condition, change_first, change_second))
            enqueue(find_exit, change_first, change_second);
    }
    ft_free_queue(&change_cord);
}