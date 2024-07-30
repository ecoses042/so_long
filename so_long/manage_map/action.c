/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:39:46 by msong             #+#    #+#             */
/*   Updated: 2024/07/18 15:54:45 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	close_hook(void *param)
{
	if (param)
		return (1);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mapi *map)
{
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	if (is_move_key(keycode) && is_movable(map, keycode))
	{
		map->move++;
		temp = ft_itoa(map->move);
		temp2 = ft_strjoin(temp, "\n");
		print_error(temp2);
		free(temp);
		free(temp2);
	}
	if (keycode == 53 || map->exit)
		close_hook(NULL);
	return (0);
}

void	set_event(t_mapi *map)
{
	mlx_hook(map->win, 17, 0, close_hook, NULL);
	mlx_key_hook(map->win, key_hook, map);
}
