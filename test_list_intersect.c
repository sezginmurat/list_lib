#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*
 * Global list objects.
 */
struct node *list1 = NULL;	
struct node *list2 = NULL;

int main(void)
{
    struct node *n[20];
    unsigned int i;

    for (i = 0; i < 20; i++) {
        n[i] = node_create(i);
        if (!n[i]) {
            // Free the previous ones.
            return -1;
        }
    }   

    list_add_node_tail(&list1, n[0]);
    list_add_node_tail(&list1, n[1]);
    list_add_node_tail(&list1, n[2]);
    list_add_node_tail(&list1, n[3]);
    list_add_node_tail(&list1, n[4]);
    list_add_node_tail(&list1, n[12]);
    list_add_node_tail(&list1, n[13]);
    list_add_node_tail(&list1, n[14]);
    list_add_node_tail(&list1, n[15]);
    list_add_node_tail(&list1, n[16]);
    list_add_node_tail(&list1, n[17]);
    list_add_node_tail(&list1, n[18]);
    list_add_node_tail(&list1, n[19]);

    list_add_node_tail(&list2, n[5]);
    list_add_node_tail(&list2, n[6]);
    list_add_node_tail(&list2, n[7]);
    list_add_node_tail(&list2, n[8]);
    list_add_node_tail(&list2, n[9]);
    list_add_node_tail(&list2, n[10]);
    list_add_node_tail(&list2, n[11]);
    list_add_node_tail(&list2, n[12]);

	printf("List 1:\n");
    list_print(list1);
	printf("\nList 2:\n");
    list_print(list2);

    struct node *nd = link_list_intersect(list1, list2);
    if (nd) {
        printf("\nIntersection node is: %p data: %d\n", nd, nd->data);
    } else {
        printf("\nThere is no intersect\n");
    }

    return 0;
}

