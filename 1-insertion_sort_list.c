#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: The list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			temp = current->prev;
		}

		current = current->next;
		print_list(*list);
	}
}

