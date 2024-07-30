/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:23:06 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 19:23:50 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int ac, char **av)
{
	t_mapi	map_array;

	if (ac < 2)
		return (1);
	if (is_invalid_file(av[1]))
		return (print_error(INVALID_FILE));
	init_map_info(&map_array);
	map_array.map = open_map(av[1]);
	if (is_invalid_map(&map_array))
	{
		ft_free_map_info(&map_array);
		return (1);
	}
	manage_window(&map_array);
	ft_free_map_info(&map_array);
	return (0);
}
