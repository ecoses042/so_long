#include "../so_long.h"

void    init_map_var(t_map_var *var)
{
    var->exit = 0;
    var->score = 0;
    var->start = 0;
}

void    update_map_var(char param, t_map_var *var)
{
    switch (param)
    {
        case 'E':
            var->exit++;
            break;
        case 'P':
            var->start++;
            break;
        case 'C':
            var->score++;
            break;
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