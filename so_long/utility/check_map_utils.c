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