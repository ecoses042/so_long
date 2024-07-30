/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:26:33 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 19:32:38 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

bool	find_start(t_mapi *map_array, int *first, int *second)
{
	*first = 0;
	while (++(*first) <= map_array->height)
	{
		*second = -1;
		while (++(*second) <= map_array->width)
		{
			if (map_array->map[*first][*second] == 'P')
				return (false);
		}
	}
	return (true);
}

bool	bfs(t_mapi *map, t_queue *find_exit, t_mapv *check_condition)
{
	t_queue	cord;

	init_queue(&cord);
	while (!queue_isempty(find_exit))
	{
		dequeue(find_exit, &cord.first, &cord.second);
		check_current(map, check_condition, cord.first, cord.second);
		put_poss_cord(map, find_exit, cord, check_condition);
	}
	ft_free_queue(find_exit);
	return (dfs_end(check_condition));
}

bool	is_invalid_path(t_mapi *map_array)
{
	int		i;
	int		j;
	t_queue	find_exit;
	t_mapv	check_condition;

	init_mapv(&check_condition);
	init_check_path(map_array);
	if (find_start(map_array, &i, &j))
	{
		print_error("cannot find the starting point\n");
		ft_free_map_info(map_array);
	}
	map_array->px = i;
	map_array->py = j;
	init_queue(&find_exit);
	enqueue(&find_exit, i, j);
	return (bfs(map_array, &find_exit, &check_condition));
}
