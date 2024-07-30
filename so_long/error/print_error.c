/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:21:21 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 19:21:50 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

bool	print_error(char	*status)
{
	int	len;

	len = ft_strlen(status);
	write(2, status, len);
	return (1);
}
