/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:20:13 by msong             #+#    #+#             */
/*   Updated: 2024/07/18 15:29:41 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

# define INVALID_FILE "Error\nFile Invalid\n"
# define ALLOC_FAIL "Error\nAllocation failed\n"
# define INVALID_SHAPE "Error\nmap shape error\n"
# define INVALID_FENCE "Error\nfence not found\n"
# define INVALID_GOAL "Error\ngoal not found\n"
# define INVALID_PATH "Error\npath not found\n"
# define MAP_SIZE 50
# define FORWARD 1
# define LEFT 2
# define BACK 3
# define RIGHT 4

//struct for storing map related information
typedef struct s_mapinfo{
	bool	endcondition;
	bool	exit;
	void	*mlx;
	void	*win;
	int		move;
	int		px;
	int		py;
	int		score_left;
	int		height;
	int		width;
	char	**map;
	char	**check_path;
}	t_mapi;

typedef struct s_map_var{
	int	exit;
	int	score;
	int	start;
}	t_mapv;

typedef struct s_queue{
	int				first;
	int				second;
	struct s_queue	*next;
	struct s_queue	*front;
	struct s_queue	*rear;
}	t_queue;

//check file
bool	is_invalid_file(char *av);

//check map invalid
bool	is_invalid_path(t_mapi *map_array);
bool	is_invalid_map(t_mapi *map_array);
//opening map
char	**open_map(char *av);

//rendering map

//movement related functions

//utility
int		ft_strlen(const	char *a);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	update_map_var(char param, t_mapv *var);
int		dequeue(t_queue *q, int *first, int *second);
void	enqueue(t_queue *q, int first, int second);
bool	queue_isempty(t_queue *q);
char	*ft_strdup(const char *src);
void	init_mapv(t_mapv *var);
bool	dfs_end(t_mapv *param);
bool	check_current(t_mapi *map, t_mapv *check_condition, int i, int j);
void	init_check_path(t_mapi *map);
void	put_poss_cord(t_mapi *map, t_queue *exit, t_queue cord, t_mapv *in);
void	init_queue(t_queue *q);
bool	is_outside(t_mapi *map, int x, int y);
void	init_map_info(t_mapi *map);
char	*ft_itoa(int n);
//allocated memory free
void	ft_free_map_info(t_mapi *map);
void	ft_free_queue(t_queue *q);
//error function
bool	print_error(char *status);

//window related fucntions
void	manage_window(t_mapi *map);
void	set_event(t_mapi *map);
void	check_window(t_mapi *map, t_queue *cord, int mode);

//movement utility functions
int		is_move_key(int key);
bool	is_movable(t_mapi *map, int key);
bool	is_exit_closed(t_mapi *map, int x, int y);

#endif
