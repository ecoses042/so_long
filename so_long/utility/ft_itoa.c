/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:07:15 by msong             #+#    #+#             */
/*   Updated: 2024/07/18 17:09:44 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ilen(int n)
{
	unsigned int	temp;
	int				len;

	len = 0;
	if (n < 0)
	{
		len++;
		temp = -n;
	}
	else
		temp = n;
	while (temp / 10 > 0)
	{
		len ++;
		temp /= 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	temp;
	int				start;
	int				len;

	start = 0;
	result = (char *)malloc(ilen(n) + 1);
	if (!result)
		return (0);
	if (n < 0)
	{
		temp = -n;
		result[0] = '-';
		start = 1;
	}
	else
		temp = n;
	len = ilen(n);
	while (len-- > start)
	{
		result[len] = (temp % 10) + '0';
		temp /= 10;
	}
	return (result);
}
