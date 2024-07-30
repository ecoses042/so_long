/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:41:03 by msong             #+#    #+#             */
/*   Updated: 2024/07/18 15:32:44 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	load_image(t_mapi	*map, char *path, int i, int j)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx, path, &height, &width);
	height = j * MAP_SIZE;
	width = i * MAP_SIZE;
	mlx_put_image_to_window(map->mlx, map->win, img, height, width);
}

void	check_exit(t_mapi *map, int i, int j, int mode)
{
	if (mode == 0)
	{
		load_image(map, "./textures/floor.xpm", i, j);
		load_image(map, "./textures/exit.xpm", i, j);
	}
	else if (mode && map->map[map->px][map->py] != 'E')
	{
		load_image(map, "./textures/floor.xpm", i, j);
		load_image(map, "./textures/exit.xpm", i, j);
	}
	else
	{
		load_image(map, "./textures/floor.xpm", i, j);
		load_image(map, "./textures/exit.xpm", i, j);
		load_image(map, "./textures/player.xpm", i, j);
	}
}

void	check_window(t_mapi *map, t_queue *cord, int mode)
{
	int	i;
	int	j;

	while (!queue_isempty(cord))
	{
		dequeue(cord, &i, &j);
		if (map->map[i][j] == '1')
			load_image(map, "./textures/wall.xpm", i, j);
		else if (map->map[i][j] == '0')
			load_image(map, "./textures/floor.xpm", i, j);
		else if (map->map[i][j] == 'C')
		{
			load_image(map, "./textures/floor.xpm", i, j);
			load_image(map, "./textures/collect.xpm", i, j);
		}
		else if (map->map[i][j] == 'P')
		{
			load_image(map, "./textures/floor.xpm", i, j);
			load_image(map, "./textures/player.xpm", i, j);
		}
		else if (map->map[i][j] == 'E')
			check_exit(map, i, j, mode);
	}
}

void	fill_window(t_mapi *map)
{
	int		i;
	int		j;
	t_queue	cord;

	i = -1;
	init_queue(&cord);
	while (++i <= map->height)
	{
		j = -1;
		while (++j <= map->width)
		{
			enqueue(&cord, i, j);
			check_window(map, &cord, 0);
		}
	}
	ft_free_queue(&cord);
}

void	manage_window(t_mapi *map)
{
	int	map_height;
	int	map_width;

	map_height = (map->height + 1) * MAP_SIZE;
	map_width = (map->width + 1) * MAP_SIZE;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map_width, map_height, "./so_long");
	fill_window(map);
	set_event(map);
	mlx_loop(map->mlx);
}
