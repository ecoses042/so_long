#ifndef SO_LONG_H
#define    SO_LONG_H

#include    <stdlib.h>
#include    <stdbool.h>
#include    <unistd.h>
#include <mlx.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

#define INVALID_FILE "File Invalid\n"
#define INVALID_MAP "Check your map file\n"
#define ALLOC_FAIL "Allocation failed\n"
//struct for storing map related information

typedef struct s_MapInfo{
    size_t height;
    size_t width;
    char **map;
} t_MapInfo;

typedef struct s_map_var{
    int exit;
    int score;
    int start;

}t_map_var;

typedef struct s_queue{
    int first;
    int second;
    struct s_queue *next;
    struct s_queue *front;
    struct s_queue *rear;
}t_queue;

//check file
bool is_invalid_file(char *av);
//check map invalid
bool is_invalid_map(t_MapInfo *Map_array);
bool is_impossible_map(t_MapInfo *Map_Array);
//opening map
char **open_map(char *av);

//rendering map

//movement related functions

//utility
size_t	ft_strlen(const	char *a);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void    update_map_var(char param, t_map_var *var);
int dequeue(t_queue *q, int *first, int *second);
void enqueue(t_queue *q, int first, int second);
int queue_isEmpty(t_queue *q);
char	*ft_strdup(const char *src);
void    init_map_var(t_map_var *var);
//error function
bool   print_error(char *status);




#endif