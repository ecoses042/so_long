#include "../so_long.h"

size_t	ft_strlen(const	char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}