#include <stdio.h>
#include <string.h>
#include "ListHelper.h"
#include "queueHelper.h"
int main(void)
{
	Queue* queue = NULL;
	List* list = NULL;

	printf("Queue:\n");

	/*Init and insert to the Queue*/
	queue = init_queue(11);
	insert(queue, 1);
	insert(queue, 2);
	insert(queue, 3);
	insert(queue, 4);
	insert(queue, 5);
	printf("the queue:");
	print_queue(queue);
	/*Top func return the first value.*/
	printf("top: %d\n", top(queue));
	printf("the queue: ");
	print_queue(queue);
	/*Pop func return the first value and remove him from the Queue.*/
	printf("pop: %d\n", pop(&queue));
	printf("the queue: ");
	print_queue(queue);
	printf("top to the secsod value (now he is the first): %d\n", top(queue));
	printf("the queue: ");
	print_queue(queue);;
	insert(queue, 0);  /*Insert 0 agein wil put him in the end to the Queue.*/
	printf("insert 0 agein.\n");
	printf("the queue: ");
	print_queue(queue);
	free_queue(&queue); /*Free the memory.*/

	printf("\n\nList:\n");
	/*Init and insert to the Queue*/
	list= init_list(10);
	add_node(list, 20);
	add_node(list, 30);
	add_node(list, 40);
	add_node(list, 50);
	add_node(list, 60);

	printf("the list:");
	print_list(list);
	printf("List AVG: %d\n", get_avg(list));  /*Can get AGV from all node in the list (e.g. getAvg(getNext(list)) )*/
	List * a = get_next(list);
	remove_node(&a);
	printf("the list:");
	print_list(list);
	printf("List AVG: %d\n", get_avg(list));
	remove_node(&(list));
	printf("the list:");
	print_list(list);
	printf("List AVG: %d\n", get_avg(list));

	/*Free the list.*/
	free_list(&list);

	system("PAUSE");
 
 	return 0;
}