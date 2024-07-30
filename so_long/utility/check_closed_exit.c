/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:40:09 by msong             #+#    #+#             */
/*   Updated: 2024/07/18 18:40:19 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

bool	is_exit_closed(t_mapi *map, int x, int y)
{
	if (map->map[x][y] == 'E' && map->endcondition)
		map->exit = true;
	return (map->map[x][y] == 'E' && !map->endcondition);
}
