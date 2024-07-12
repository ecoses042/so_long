#include "../so_long.h"

int isEmpty(t_queue *q) 
{
    return (q->front == NULL);
}

void enqueue(t_queue *q, int first, int second) 
{
    t_queue *newNode;
    
    newNode = (t_queue *)malloc(sizeof(t_queue));
    if (!newNode)
    {
        print_error(ALLOC_FAIL);
        return ;
    }
    newNode->first = first;
    newNode->second = second;
    newNode->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = newNode;
    else 
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(t_queue *q, int *first, int *second) 
{
    t_queue *temp;

    if (isEmpty(q))
        return (0);
    temp = q->front;
    *first = temp->first;
    *second = temp->second;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return 1;
}