#include "ListHelper.h"


List* init_list(int val)
{
	List* node = (List*)malloc(sizeof(List));
	node->value = val;
	node->next = NULL;
	node->prev = NULL;
	node->head = node;
	node->last = node;
	node->length = 1;
	node->sum = val;
	return node;
}

void add_node(List* head, int val)
{ 
	List* node = (List*)malloc(sizeof(List));
	node->value = val;
	node->next = NULL;
	head->last->next = node;
	node->prev = head->last;	
	node->head = head;
	node->last = node;
	head->last = node;
	++(head->length);
	head->sum += val;

}

void remove_node(List** node)
{
	if ((*node) == NULL )
		return;

	if ((*node) != ((*node))->head)
	{
		List* temp = (*node);
		(*node)->prev->next = (*node)->next;
		--(*node)->head->length;
		(*node)->head->sum -= temp->value;
		free(temp);

	}
	else if((*node)->next != NULL)  /*node is the head and he have at least 1 next.*/
	{

		/*switch between values*/
		(*node)->value += (*node)->next->value;
		(*node)->next->value = (*node)->value - (*node)->next->value;
		(*node)->value -= (*node)->next->value;

		List* temp = (*node)->next;
		(*node)->next = (*node)->next->next;
		(*node)->next->prev = *node;
		(*node)->prev = NULL;
		remove_node(&temp);

	}
	else /*node is the head and tha only obj in the list.*/
	{
		/*length and sum is in 0*/
		free(*node);
		*node = NULL;
	}
}

List* get_head(List* node)
{
	return node->head;
}
List* get_first(List* node)
{
	return get_head(node);
}
List* get_last(List* node)
{
	return get_head(node)->last;
}
List* get_next(List* node)
{
	return node->next;
}
List* get_prev(List* node)
{
	return node->prev;
}
List* get_value(List* node)
{
	return node->value;
}

int get_length(List* node)
{
	return get_head(node)->length;
}
int get_avg(List* node)
{
	return get_head(node)->sum / get_head(node)->length;
}
void print_list(List* node)
{
	if (node != NULL)
	{
		printf("%d->", node->value);
		print_list(node->next);
	}
	else
	{
		printf("NULL\n");

	}
}

void free_list(List** list)
{
	if (*list != NULL)
	{
		free_list(&((*list)->next));
		free(*list);
	}
}