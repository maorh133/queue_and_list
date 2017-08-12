
#include "queueHelper.h"

Queue* init_queue(int val)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->head = q;
	q->last = q;
	q->next = NULL;
	q->length = 1;
	q->value = val;
	return q;
}
void insert(Queue* head, int val)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->head = head;
	head->last->next = q;
	q->last = q;
	q->next = NULL;
	q->value = val;
	head->last = q;
	++head->length;
}
int get_queue_length(Queue* q)
{
	return q->head->length;
}
int top(Queue* q)
{
	return q->head->value;
}
int pop(Queue** head)
{

	int val = (*head)->value;
	Queue* temp = *head;
	if ((*head)->next != NULL)
	{

		(*head)->next->length = (*head)->length - 1;
		(*head)->next->head = (*head)->next;
		(*head)->next->last = (*head)->last;
		*head = (*head)->next;
	}
	else
	{
		*head = NULL;
	}
	free(temp);
	return val;
}
void print_queue(Queue* q)
{
	if (q != NULL)
	{
		printf("%d->", q->value);
		print_queue(q->next);
	}
	else
	{
		printf("NULL\n");
	}
}
void free_queue(Queue** q)
{
	if (*q != NULL)
	{
		free_queue(&((*q)->next));
		free(*q);
	}
}