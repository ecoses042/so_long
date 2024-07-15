#include "../so_long.h"

bool queue_isEmpty(t_queue *q) 
{
    return (q->front == NULL);
}

void init_queue(t_queue *q)
{
    q->first = 0;
    q->second = 0;
    q->next = NULL;
    q->front = NULL;
    q->rear = NULL;
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
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(t_queue *q, int *first, int *second) 
{
    t_queue *temp;

    if (queue_isEmpty(q))
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