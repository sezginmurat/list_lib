#include "list.h"

/*
 * node_create()
 *	Creates a node.
 */
struct node *node_create(int data)
{
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        printf("Unable to allocate memory for node\n");
        return NULL;
    }

    n->data = data;
    n->next = NULL;

    return n;
}

/*
 * node_free()
 *	Frees a node.
 */
void node_free(struct node *n)
{
    if (!n) {
        return;
    }

    free(n);
}

/*
 * list_lenght_get()
 *	Gets the length of a list.
 */
int list_lenght_get(struct node *list)
{
    int count = 0;

    while (list) {
        count++;
        list = list->next;
    }
    return count;
}

/*
 * link_list_intersect()
 *	FInds the intersection node of 2 lists.
 */
struct node *link_list_intersect(struct node *list1, struct node *list2)
{
    struct node *long_list;
    struct node *short_list;
    int diff = 0;

	/*
	 * Get the lengths of the lists.
	 */
    int len1 = list_lenght_get(list1);
    int len2 = list_lenght_get(list2);

	/*
	 * Find which list is long and which list is short
	 * and find the absolute lenght difference.
	 */
    if (len1 >= len2) {
        diff = len1 - len2;
        long_list = list1;
        short_list = list2;
    } else {
        diff = len2 - len1;
        long_list = list2;
        short_list = list1;
    }

	/*
	 * Move the long list with the amount of diff. 
	 */
    if (diff) {
        while (diff--) {
            long_list = long_list->next;
        }
    }

	/*
	 * Compare the nodes of the list.
	 */
    while (len1--) {
        if (long_list == short_list) {
			/*
			 * nodes are equal return the long one (doesn't matter).)
			 */
            return long_list;
        }
		/*
		 * Move the lists, nodes are not equal in this iteration.
		 */
        long_list = long_list->next;
        short_list = short_list->next;
    }

	/*
	 * There is no intersection point.
	 */
    return NULL;
}

/*
 * list_add_node_tail()
 *	Adds an allocated node to a linled list tail.
 */
void list_add_node_tail(struct node **list, struct node *n)
{
    struct node *curr = *list;

    if (!*list) {
        *list = n;
        return;
    }

    while (curr->next) {
        curr = curr->next;
    }

    curr->next = n;
}


/*
 * list_add_data_head()
 *	Adds a node by data to the head of the linked list.
 */
void list_add_data_head(struct node **list, int data)
{
	struct node *n = (struct node *)malloc(sizeof(struct node));
	if (!n) {
		printf("Unable to allocate memory for node\n");
		return;
	}

	n->data = data;
	n->next = *list;
	*list = n;
}

/*
 * list_add_data_tail()
 *	Adds a node by data to the tail of the linked list.
 */
void list_add_data_tail(struct node **list, int data)
{
	struct node *nd = (struct node *)malloc(sizeof(struct node));
	if (!nd) {
		printf("Unable to allocate memory for node\n");
		return;
	}

	nd->data = data;
	nd->next = NULL;

	if (!(*list)) {
		*list = nd;	
		return;
	}

	struct node *n = *list;

	while(n->next) {
		n = n->next;
	}

	n->next = nd;
}

/*
 * list_print()
 *	Prints linked list.
 */
void list_print(struct node *list)
{
	if (!list) {
		printf("list is empty, cannot print\n");
		return;
	}

	struct node *n = list;

	while (n) {
		printf("%d->", n->data);
		n = n->next;
	}

	printf("NULL\n");

}

/*
 * list_data_look_up()
 *	Look ups a node by a data inside the linked list.
 */
bool list_data_look_up(struct node *list, int data)
{
	while (list) {
		if (list->data == data) {
			return true;
		}

		list = list->next;
	}

	return false;
}

/*
 * list_remove_node_by_data()
 *	Remove a node by data from linked list.
 */
void list_remove_node_by_data(struct node **list, int data)
{
	/*
	 * If list is empty, just return.
	 */
	if (!*list) {
		printf("list is empty\n");
		return;
	}

	/*
	 * curr is our list head.
	 */
	struct node *curr = *list;
	struct node *tmp;

	/*
	 * If there is multiple occurences at the head of the list,
	 * remove all of them.
	 * 1->1->1->5->6->null
	 */
	while (curr && (curr->data == data)) {
			tmp = curr;
			*list = curr->next;
			curr = *list;
			free(tmp);
	}

	/*
	 * Check the list. Did we remove all the nodes?
	 */
	if (!*list) {
		printf("list is empty. All the occurences removed from the head\n");
		return;
	}

	/*
	 * There are more nodes in the list. Check them as well.
	 * If we find more occurence, prev->next will be bound to curr->next.
	 */
	struct node *prev = curr;
	curr = curr->next;

	while (curr) {	
		if (curr->data == data) {
			tmp = curr;
			prev->next = curr->next;
			curr = curr->next;
			free(tmp);
			continue;
		}

		prev = curr;
		curr = curr->next;
	}			
}

/*
 * list_reverse()
 *	Reverses a linked list.
 */
void list_reverse(struct node **list)
{
	struct node *prev = NULL;
	struct node *curr = *list;
	struct node *next_node = *list;

	/*
	 * If list is empty, just return.
	 */
	if (!*list) {
		printf("list is empty\n");
		return;
	}

	while (curr) {
		next_node = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next_node;
	}
	*list = prev;
}

