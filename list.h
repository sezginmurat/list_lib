#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * node structure.
 */
struct node {
	struct node *next;
	int data;
};

extern struct node *node_create(int data);
extern void node_free(struct node *n);
extern int list_lenght_get(struct node *list);
extern struct node *link_list_intersect(struct node *list1, struct node *list2);
extern void list_add_node_tail(struct node **list, struct node *n);
extern void list_add_data_head(struct node **list, int data);
extern void list_add_data_tail(struct node **list, int data);
extern void list_print(struct node *list);
extern bool list_data_look_up(struct node *list, int data);
extern void list_remove_node_by_data(struct node **list, int data);
extern void list_reverse(struct node **list);
