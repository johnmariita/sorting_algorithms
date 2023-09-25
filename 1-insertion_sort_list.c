#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *ptr = current;
		while (ptr->prev != NULL && ptr->n < ptr->prev->n)
		{
			listint_t *tempNext = ptr->next;
			listint_t *tempPrev = ptr->prev;

			tempPrev->next = ptr->next;
			if (ptr->next != NULL)
				ptr->next->prev = tempPrev;

			ptr->next = tempPrev;
			ptr->prev = tempPrev->prev;

			if (tempPrev->prev != NULL)
				tempPrev->prev->next = ptr;

			tempPrev->prev = ptr;

			if (ptr->prev == NULL)
				*list = ptr;

			ptr = tempNext;
		}

		current = current->next;
	}
}
