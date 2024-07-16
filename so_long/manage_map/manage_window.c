#include "../so_long.h"


//this file contains
//function working as the manager of whole window 
void load_image(t_MapInfo *map, char *path, int i, int j)
{
    int width;
    int height;
    void *img;

    img =  mlx_xpm_file_to_image(map->mlx, path, &width, &height);
    mlx_put_image_to_window(map->mlx, map->win, img, i * MAP_SIZE, j * MAP_SIZE);
}

void check_window(t_MapInfo *map, t_queue *cord)
{
    int i;
    int j;
    while (!queue_isEmpty(cord))
    {
        dequeue(cord, &i, &j);
        if (map->map[i][j] == '1')
            load_image(map, "./texture/wall.xpm", i, j);
        else if (map->map[i][j] == '0')
            load_image(map, "./texture/floor.xpm",i ,j);
        else if (map->map[i][j] == 'C')
        {
            load_image(map, "./texture/floor.xpm",i ,j);
            load_image(map, "./texture/collect.xpm", i, j);
        }
        else if (map->map[i][j] == 'P')
        {
            load_image(map, "./texture/floor.xpm",i ,j);
            load_image(map, "./texture/player.xpm",i, j);
        }
        else if (map->map[i][j] == 'E')
            load_image(map, "./texture/exit.xpm", i, j);
    }
}

void fill_window(t_MapInfo *map)
{
    int i;
    int j;
    t_queue cord;

    i = -1;
    init_queue(&cord);
    while (++i <= map->height)
    {
        j = -1;
        while (++j <= map->width)
        {
            enqueue(&cord, i, j);
            check_window(map, &cord);        
        }
    }
    ft_free_queue(&cord);
}

void manage_window(t_MapInfo *map)
{
    int map_height;
    int map_width;

    map_height = (map->height +  1) * MAP_SIZE;
    map_width = (map->width +  1) * MAP_SIZE;
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map_height, map_width, "./so_long");
    fill_window(map);
    set_event(map);
    //implement the key reaction
    //implement the end conditiion
    mlx_loop(map->mlx);
}
//updating player movement and status of collectable
//check end condition and open exit