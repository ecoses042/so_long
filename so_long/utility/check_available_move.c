#include "../so_long.h"
#include <stdio.h>
int is_move_key(int keycode)
{
  	if (keycode == 2 || keycode == 124)
		return (RIGHT);
	else if (keycode == 0 || keycode == 123)
		return (LEFT);
	else if (keycode == 13 || keycode == 126)
		return (FORWARD);
	else if (keycode == 1 || keycode == 125)
		return (BACK);
    else
        return (0);
}

void get_next_cord(t_MapInfo *map, t_queue *q, int key)
{
    int next_x;
    int next_y;

    next_x = map->px;
    next_y = map->py;
    switch(is_move_key(key))
    {
        case FORWARD:
            next_y = map->py - 1;
            break;
        case LEFT:
            next_x = map->px - 1;
            break;
        case BACK:
            next_y = map->py + 1;
            break;
        case RIGHT:
            next_x = map->px + 1;
            break;
    }
    enqueue(q, next_x, next_y);
}

void enqueue_next_cord(t_MapInfo *map, t_queue *q, int next_x, int next_y)
{
    enqueue(q, map->px, map->py);
    enqueue(q, next_x, next_y);
    if (map->map[next_x][next_y] == 'C')
        map->score_left -= 1;
    if (map->map[next_x][next_y] == 'E' && map->score_left == 0)
        map->endcondition = true;
    map->map[next_x][next_y] = 'P';
    map->px = next_x;
    map->py = next_y;
}
bool next_cord(t_MapInfo *map, t_queue *q, int key)
{
    int next_x;
    int next_y;
    t_queue store_next;

    init_queue(&store_next);
    get_next_cord(map, &store_next, key);
    dequeue(&store_next, &next_x, &next_y);
    //printf("this is player cord: %d %d\n",map->px, map->py);
    printf("this is next_cord: %d %d\n", next_x, next_y);
    if (is_outside(map, next_x, next_y))
    {
        map->map[map->px][map->py] = 'P';
        ft_free_queue(&store_next);
        return (false);
    }
    enqueue_next_cord(map, q, next_x, next_y);
    ft_free_queue(&store_next);
    return (true);
}

bool is_movable(t_MapInfo *map,int key)
{
    bool flag;
    t_queue reload_cord;

    init_queue(&reload_cord);
    map->map[map->px][map->py] = '0';
    flag = next_cord(map, &reload_cord, key);
    check_window(map, &reload_cord);
    ft_free_queue(&reload_cord);
    return (flag);
    //check that next cord is movable.
    //return false if cannot be done
    //reload the windows by updating map->map, enqueue the current and nexxt_cord
    //finally calling check_window
    //after updated, check map for end condition.
    //if moved posistion is score, lower score_left.
    //if moved posistion is exit and score_left == 0, end the program.
}