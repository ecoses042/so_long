/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:48:25 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 20:15:55 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	init_mapv(t_mapv *var)
{
	var->exit = 0;
	var->score = 0;
	var->start = 0;
}

void	update_map_var(char param, t_mapv *var)
{
	if (param == 'E')
		var->exit++;
	if (param == 'P')
		var->start++;
	if (param == 'C')
		var->score++;
}

//return true if outside
//false if inside or not 1
bool	is_outside(t_mapi *map, int x, int y)
{
	int	height;
	int	width;

	height = map->height;
	width = map->width;
	if ((x > height || x < 0) || (y > width || y < 0))
		return (true);
	return (map->map[x][y] == '1');
}
