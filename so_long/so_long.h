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
    int height;
    int width;
    char **map;
    char **check_path;
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
bool is_invalid_path(t_MapInfo *Map_array);
bool is_invalid_map(t_MapInfo *Map_array);
//opening map
char **open_map(char *av);

//rendering map

//movement related functions

//utility
int	ft_strlen(const	char *a);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void    update_map_var(char param, t_map_var *var);
int dequeue(t_queue *q, int *first, int *second);
void enqueue(t_queue *q, int first, int second);
bool queue_isEmpty(t_queue *q);
char	*ft_strdup(const char *src);
void    init_map_var(t_map_var *var);
bool dfs_end(t_map_var *param);
bool check_current(t_MapInfo *Map, t_map_var *check_condition, int i, int j);
void init_check_path(t_MapInfo *Map);
void enqueue_possible_cord(t_MapInfo *Map,t_queue *find_exit, t_queue cord, t_map_var *condition);
void init_queue(t_queue *q);

//allocated memory free
void ft_free_Map_Info(t_MapInfo *Map);
void ft_free_queue(t_queue *q);
//error function
bool   print_error(char *status);




#endif