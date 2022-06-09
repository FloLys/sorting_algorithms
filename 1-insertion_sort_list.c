#include "sort.h"

/**
* insertion_sort_list - sort a double linked list with insertion sort
* and print the list after each time you swap two elements
* @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL;
	listint_t *current = *list;

	if (!list)
		list = NULL;

	if (current->next == NULL)
		return;

	while (current)
	{
		aux = current;
		while (current->prev && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			if (current->prev->prev)
				current->prev->prev->next = current;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (!current->prev)
				*list = current;
			print_list(*list);
		}
		current = aux->next;
	}
}
