/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:24:16 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 19:25:09 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

bool	is_ber(char	*av, char	*to_find)
{
	int	i;

	i = 0;
	if (ft_strlen(av) < ft_strlen(to_find))
		return (false);
	while (av[i])
	{
		if (av[i] != to_find[i])
			return (false);
		i++;
	}
	return (true);
}

bool	is_invalid_file(char	*av)
{
	bool	first;

	first = true;
	while (*av)
	{
		if (first == false && *av == '.')
		{
			if (is_ber(av, ".ber"))
				return (false);
		}
		av++;
		first = false;
	}
	return (true);
}
