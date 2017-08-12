#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct List{
	int value;
	struct List* next;
	struct List* prev;
	struct List* head;
	struct List* last;
	int length;
	int sum;

}List;


List* init_list(int val);
void add_node(List* head, int val);
void remove_node(List** node);
List* get_head(List* node);
List* get_first(List* node);
List* get_last(List* node);
List* get_next(List* node);
List* get_prev(List* node);
List* get_value(List* node);
int get_length(List* node);
int get_avg(List* node);
void print_list(List* node);						  
void free_list(List** list);