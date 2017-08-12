#pragma once

#include <stdlib.h>

typedef struct Queue
{
	struct Queue* head;
	struct Queue* last;
	struct Queue* next;
	int value;
	int length;
}Queue;

Queue* init_queue(int);
void insert(Queue*, int);
int get_queue_length(Queue*);
int top(Queue*);
int pop(Queue**);
void print_queue(Queue*);
void free_queue(Queue**);