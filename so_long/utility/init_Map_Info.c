#include "../so_long.h"

void init_Map_Info(t_MapInfo *Map)
{
    Map->endcondition = false;
    Map->move = 0;
    Map->px = 0;
    Map->py = 0;
    Map->score_left = 0;
    Map->height = 0;
    Map->width = 0;
}