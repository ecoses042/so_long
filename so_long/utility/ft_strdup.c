#include "../so_long.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*cpy;
	size_t	i;

	len = ft_strlen(src);
	i = 0;
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (0);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}