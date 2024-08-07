/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:50:58 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 20:07:02 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!result)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = ' ';
	i = 0;
	while (i < ft_strlen(s2))
	{
		result[i + ft_strlen(s1) + 1] = s2[i];
		i++;
	}
	result[i + ft_strlen(s1) + 1] = '\0';
	return (result);
}
