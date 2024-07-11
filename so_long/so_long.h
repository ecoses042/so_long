#ifndef SO_LONG_H
#define    SO_LONG_H

#include    <stdlib.h>
#include    <stdbool.h>
#include    <unistd.h>
#include <mlx.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

#define INVALID_FILE "File Invalid\n"

//check file
bool is_invalid_file(char *av);
//check map invalid
bool is_invalid_map(char **map);

//opening map
char **open_map(char *av);

//rendering map

//movement related functions

//utility
size_t	ft_strlen(const	char *a);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
//error function
void    print_error(char *status);

//struct for storing map related information

typedef struct s_MapInfo{
    int height;
    int width;
    char **map;
} t_MapInfo;

#endif