/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:09:39 by msong             #+#    #+#             */
/*   Updated: 2024/07/18 16:34:46 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	issep(char a, char b)
{
	if (a == b || a == ' ')
		return (0);
	return (1);
}

static char	**stringnum(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**a;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && !issep(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && issep(s[i], c))
			i++;
	}
	a = (char **)malloc(sizeof(char *) * (count + 1));
	return (a);
}

static char	*word(char const *str, char c, size_t i)
{
	char	*word;
	size_t	i2;
	size_t	len;

	i2 = i;
	len = 0;
	while (str[i2] && issep(str[i2], c))
	{
		len++;
		i2++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	i2 = 0;
	while (str[i] && issep(str[i], c))
	{
		word[i2] = str[i];
		i2++;
		i++;
	}
	word[i2] = '\0';
	return (word);
}

static char	**free_and_ret_nul(char **result, size_t i)
{
	i -= 1;
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	result = stringnum(s, c);
	if (!result)
		return (0);
	while (s[i2])
	{
		while (s[i2] && !issep(s[i2], c))
			i2++;
		if (s[i2])
		{
			result[i] = word(s, c, i2);
			if (!result[i])
				return (free_and_ret_nul(result, i));
			i++;
		}
		while (s[i2] && issep(s[i2], c))
			i2++;
	}
	result[i] = 0;
	return (result);
}
