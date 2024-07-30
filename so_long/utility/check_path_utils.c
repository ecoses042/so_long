/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:48:55 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 20:05:56 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

bool	dfs_end(t_mapv *param)
{
	return (!param->exit && !param->score);
}

bool	check_current(t_mapi *map, t_mapv *check_in, int i, int j)
{
	if (map->check_path[i][j] == '1')
		return (true);
	if (map->map[i][j] == 'C')
		check_in->score += 1;
	else if (map->map[i][j] == 'P')
		check_in->start += 1;
	else if (map->map[i][j] == 'E')
		check_in->exit += 1;
	map->check_path[i][j] = '1';
	return (false);
}

bool	is_checked(t_mapi *map, int x, int y)
{
	return (map->check_path[x][y] == '1' || map->map[x][y] == '1');
}

void	init_check_path(t_mapi *map)
{
	int	i;
	int	j;

	i = -1;
	map->move = 0;
	map->check_path = malloc(sizeof(char *) * (map->height + 2));
	if (!map->check_path)
		return ;
	while (++i <= map->height)
	{
		j = -1;
		map->check_path[i] = malloc(sizeof(char) * (map->width + 2));
		if (!map->check_path[i])
			return ;
		while (++j <= map->width)
			map->check_path[i][j] = 0;
	}
	map->check_path[map->height + 1] = NULL;
}

void	put_poss_cord(t_mapi *map, t_queue *exit, t_queue cord, t_mapv *in)
{
	int		dx;
	int		dy;
	t_queue	change_cord;

	init_queue(&change_cord);
	enqueue(&change_cord, -1, 0);
	enqueue(&change_cord, 1, 0);
	enqueue(&change_cord, 0, -1);
	enqueue(&change_cord, 0, 1);
	while (!queue_isempty(&change_cord))
	{
		dequeue(&change_cord, &dx, &dy);
		dx += cord.first;
		dy += cord.second;
		if (!is_outside(map, dx, dy) && !check_current(map, in, dx, dy))
			enqueue(exit, dx, dy);
	}
	ft_free_queue(&change_cord);
}
