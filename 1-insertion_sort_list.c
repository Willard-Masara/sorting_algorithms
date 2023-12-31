#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	current = (*list)->next;

	while (current != NULL)
	{
	prev = current->prev;

	while (prev != NULL && prev->n > current->n)
	{
	    /* Swap nodes */
	    if (current->next != NULL)
		current->next->prev = prev;
	    prev->next = current->next;
	    current->prev = prev->prev;
	    current->next = prev;
	    prev->prev = current;

	    if (current->prev == NULL)
		*list = current;
	    else
		current->prev->next = current;

	    print_list(*list);

	    prev = current->prev;
	}

	current = current->next;
	}
}
