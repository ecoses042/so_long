/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msong <msong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:51:30 by msong             #+#    #+#             */
/*   Updated: 2024/07/16 20:09:20 by msong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

bool	queue_isempty(t_queue *q)
{
	return (q->front == NULL);
}

void	init_queue(t_queue *q)
{
	q->first = 0;
	q->second = 0;
	q->next = NULL;
	q->front = NULL;
	q->rear = NULL;
}

void	enqueue(t_queue *q, int first, int second)
{
	t_queue	*newnode;

	newnode = (t_queue *)malloc(sizeof(t_queue));
	if (!newnode)
	{
		print_error(ALLOC_FAIL);
		return ;
	}
	newnode->first = first;
	newnode->second = second;
	newnode->next = NULL;
	if (q->rear == NULL)
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}

int	dequeue(t_queue *q, int *first, int *second)
{
	t_queue	*temp;

	if (queue_isempty(q))
		return (0);
	temp = q->front;
	*first = temp->first;
	*second = temp->second;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
	return (1);
}
