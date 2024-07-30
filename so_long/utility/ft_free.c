/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:49:58 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 19:50:21 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_free_map_info(t_mapi *map)
{
	int	i;

	i = map->height - 1;
	if (!map)
		return ;
	while (++i <= map->height)
		free(map->map[i]);
	free(map->map);
	if (!map->check_path)
		return ;
	i = map->height - 1;
	while (++i <= map->height)
		free(map->check_path[i]);
	free(map->check_path);
}

void	ft_free_queue(t_queue *q)
{
	int	placeholder1;
	int	placeholder2;

	placeholder1 = 0;
	placeholder2 = 0;
	if (!q)
		return ;
	while (!queue_isempty(q))
		dequeue(q, &placeholder1, &placeholder2);
}
