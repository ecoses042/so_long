/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:28:28 by msong             #+#    #+#             */
/*   Updated: 2024/07/18 15:30:42 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*open_map_util(char *lines, char *line)
{
	char	*temp;

	temp = NULL;
	if (!lines)
		lines = ft_strdup(line);
	else
	{
		temp = ft_strjoin(lines, line);
		free(lines);
		lines = temp;
	}
	return (lines);
}

char	**open_map(char *av)
{
	int		fd;
	char	*line;
	char	*lines;
	char	**result;

	line = " ";
	lines = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		print_error(INVALID_FILE);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines = open_map_util(lines, line);
		free(line);
	}
	close(fd);
	result = ft_split(lines, '\n');
	free(lines);
	return (result);
}
