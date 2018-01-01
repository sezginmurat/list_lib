#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*
 * Global list object.
 */
struct node *list = NULL;

/*
 * Test Code.
 */
int main(void)
{
	printf("Creating link list\n");

	list_add_data_head(&list, 1);
	list_add_data_head(&list, 1);
	list_add_data_tail(&list, 5);
	list_add_data_tail(&list, 6);
	list_add_data_tail(&list, 1);
	list_add_data_tail(&list, 7);
	list_add_data_tail(&list, 1);
	list_add_data_tail(&list, 12);
	list_add_data_tail(&list, 1);

	list_print(list);

	printf("\nLook up 3 in the list\n");
	if (list_data_look_up(list, 3)) {
		printf("Yes, list has 3\n");
	} else {
		printf("No, list does not have 3\n");
	}

	printf("\nLook up 5 in the list\n");
	if (list_data_look_up(list, 5)) {
		printf("Yes, list has 5\n");
	} else {
		printf("No, list does not have 5\n");
	}

	printf("\nRemove 1s from the list\n");
	list_remove_node_by_data(&list, 1);

	list_print(list);

	printf("\nReverse list\n");
	list_reverse(&list);
	list_print(list);

	return 0;
}
