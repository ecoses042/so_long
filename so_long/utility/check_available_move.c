/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_available_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:47:09 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 20:18:26 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	is_move_key(int keycode)
{
	if (keycode == 2 || keycode == 124)
		return (BACK);
	else if (keycode == 0 || keycode == 123)
		return (FORWARD);
	else if (keycode == 13 || keycode == 126)
		return (LEFT);
	else if (keycode == 1 || keycode == 125)
		return (RIGHT);
	else
		return (0);
}

void	get_next_cord(t_mapi *map, t_queue *q, int key)
{
	int	next_x;
	int	next_y;

	next_x = map->px;
	next_y = map->py;
	if (is_move_key(key) == FORWARD)
		next_y = map->py - 1;
	else if (is_move_key(key) == LEFT)
		next_x = map->px - 1;
	else if (is_move_key(key) == BACK)
		next_y = map->py + 1;
	else if (is_move_key(key) == RIGHT)
		next_x = map->px + 1;
	enqueue(q, next_x, next_y);
}

void	enqueue_next_cord(t_mapi *map, t_queue *q, int next_x, int next_y)
{
	enqueue(q, map->px, map->py);
	enqueue(q, next_x, next_y);
	if (map->map[next_x][next_y] == 'C')
		map->score_left -= 1;
	if (map->score_left == 0 && map->endcondition == false)
		map->endcondition = true;
	if (map->map[next_x][next_y] != 'E')
		map->map[next_x][next_y] = 'P';
	map->px = next_x;
	map->py = next_y;
}

bool	next_cord(t_mapi *map, t_queue *q, int key)
{
	int		next_x;
	int		next_y;
	t_queue	store_next;

	init_queue(&store_next);
	get_next_cord(map, &store_next, key);
	dequeue(&store_next, &next_x, &next_y);
	if (is_outside(map, next_x, next_y))
	{
		if (map->map[map->px][map->py] != 'E')
			map->map[map->px][map->py] = 'P';
		ft_free_queue(&store_next);
		return (false);
	}
	is_exit_closed(map, next_x, next_y);
	enqueue_next_cord(map, q, next_x, next_y);
	ft_free_queue(&store_next);
	return (true);
}

bool	is_movable(t_mapi *map, int key)
{
	bool	flag;
	t_queue	reload_cord;

	init_queue(&reload_cord);
	if (map->map[map->px][map->py] != 'E')
		map->map[map->px][map->py] = '0';
	flag = next_cord(map, &reload_cord, key);
	check_window(map, &reload_cord, 1);
	ft_free_queue(&reload_cord);
	return (flag);
}
