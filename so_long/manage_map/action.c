#include "../so_long.h"

int close_hook(void *param)
{
    if (param)
        return (1);
    print_error("window closed\n");
    exit(0);
    return 0;
}
#include <stdio.h>

int key_hook(int keycode, t_MapInfo *map)
{
    if (is_move_key(keycode) && is_movable(map, keycode))//&& is_movable(map, keycode)
    {
        map->move += 1;
        printf("count: %d\n", map->move);
    }
    if (keycode == 53 || map->endcondition) // ESC 키 코드 혹은 엔딩 컨디션이 맞다면 프로그램 종료
        close_hook(NULL);
    //check if move is move key 
    //check if move key can move a character
    //if cannot move, do nothing
    //if can be moved, reload the screen of current and next location of character
    return (0);
    //when moved, increase map->count by 1
    //function for character moving
}

void set_event(t_MapInfo *map)
{
    mlx_hook(map->win, 17, 0, close_hook, NULL);
    mlx_key_hook(map->win, key_hook, map);
}