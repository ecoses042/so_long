/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:26:17 by msong             #+#    #+#             */
/*   Updated: 2024/07/22 13:41:26 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list{
	char			*content;
}t_list;

size_t	gnl_strlen(char const *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_cut(char *s, ssize_t i);

char	*get_next_line(int fd);
int		gnl_start(int fd, t_list *head);
char	*gnl_get_line(t_list *head);
ssize_t	gnl_strchr(char *str, int c);
#endif
