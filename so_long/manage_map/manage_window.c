#include "../so_long.h"

#include <stdio.h>

//this file contains
//function working as the manager of whole window 
void load_image(t_MapInfo *map, char *path, int i, int j)
{
    int width;
    int height;
    void *img;

    img =  mlx_xpm_file_to_image(map->mlx, path, &width, &height);
    printf("load_image setting img complete\n");
    if (!img)
        printf("img null\n");
    mlx_put_image_to_window(map->mlx, map->win, img, i * MAP_SIZE, j * MAP_SIZE);
    printf("upate map complete\n");
}

void check_window(t_MapInfo *map, t_queue *cord)
{
    int i;
    int j;

    dequeue(cord, &i, &j);
    if (map->map[i][j] == '1')
        load_image(map, "./texture/wall.xpm", i, j);
    else if (map->map[i][j] == '0')
        load_image(map, "./texture/floor.xpm",i ,j);
    else if (map->map[i][j] == 'C')
    {
        load_image(map, "./texture/collect.xpm", i, j);
        load_image(map, "./texture/floor.xpm",i ,j);
    }
    else if (map->map[i][j] == 'P')
        load_image(map, "./texture/player.xpm",i, j);
     else if (map->map[i][j] == 'E')
        load_image(map, "./texture/exit.xpm", i, j);
}

void fill_window(t_MapInfo *map)
{
    int i;
    int j;
    t_queue cord;

    i = -1;
    init_queue(&cord);
    while (++i <= map->height -1 )
    {
        j = -1;
        while (++j <= map->width - 1)
        {
            enqueue(&cord, i, j);
            check_window(map, &cord);        
        }
    }
    ft_free_queue(&cord);
}

void manage_window(t_MapInfo *map)
{
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->height * MAP_SIZE, map->width * MAP_SIZE, "./so_long");
    fill_window(map);
    //implement the key reaction
    //implement the end conditiion
    mlx_loop(map->mlx);
}
//updating player movement and status of collectable
//check end condition and open exit