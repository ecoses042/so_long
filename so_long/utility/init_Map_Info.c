/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:51:21 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 20:06:46 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	init_map_info(t_mapi *map)
{
	map->exit = false;
	map->endcondition = false;
	map->move = 0;
	map->px = 0;
	map->py = 0;
	map->score_left = 0;
	map->height = 0;
	map->width = 0;
}
