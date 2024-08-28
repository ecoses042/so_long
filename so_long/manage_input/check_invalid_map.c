/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_INVALID_MAP.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:25:16 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 19:31:40 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

bool	is_invalid_shape(t_mapi	*map_array)
{
	int	i;
	int	current_len;
	int	len;

	i = 0;
	if (!map_array->map)
		return (print_error(INVALID_FILE));
	len = ft_strlen(map_array->map[i]);
	while (map_array->map[i])
	{
		current_len = ft_strlen(map_array->map[i]);
		if (current_len != len)
			return (print_error(INVALID_SHAPE));
		i++;
	}
	map_array->width = current_len - 1;
	map_array->height = i - 1;
	return (false);
}

bool	invalid_char(char param)
{
	bool	flag1;
	bool	flag2;

	flag1 = false;
	flag2 = false;
	if (param != '0' && param != '1')
		flag1 = true;
	if (param != 'C' && param != 'E' && param != 'P')
		flag2 = true;
	return (flag1 && flag2);
}

bool	is_invalid_fence(t_mapi *map_array)
{
	int	i;
	int	j;
	int	height;
	int	width;

	height = map_array->height;
	width = map_array->width;
	i = -1;
	while (++i <= height)
	{
		j = -1;
		while (++j <= width)
		{
			if ((i == height || j == width) && map_array->map[i][j] != '1')
				return (print_error(INVALID_FENCE));
			else if (invalid_char(map_array->map[i][j]))
				return (print_error(INVALID_CHAR));
		}
	}
	return (false);
}

bool	is_invalid_goal(t_mapi *map_array)
{
	t_mapv	check;
	int		i;
	int		j;

	i = -1;
	init_mapv(&check);
	while (++i <= map_array->height)
	{
		j = -1;
		while (++j <= map_array->width)
		{
			update_map_var(map_array->map[i][j], &check);
		}
	}
	map_array->score_left = check.score;
	if (check.exit != 1 || check.score == 0 || check.start != 1)
		return (true);
	return (false);
}

bool	is_invalid_map(t_mapi *map_array)
{
	int	height;
	int	width;

	if (is_invalid_shape(map_array))
		return (true);
	height = map_array->height + 1;
	width = map_array->width + 1;
	if (height > HEIGHT_LIMIT || width > WIDTH_LIMIT)
		return (print_error(INVALID_SHAPE));
	if (is_invalid_fence(map_array))
		return (true);
	if (is_invalid_goal(map_array))
		return (print_error(INVALID_GOAL));
	if (is_invalid_path(map_array))
		return (print_error(INVALID_PATH));
	return (false);
}
