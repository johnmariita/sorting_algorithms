#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = *list, *ptr2 = list, *sptr;
	int *temp, temp2;
	listint_t *sorted;

	if (ptr == NULL || ptr->next == NULL)
		return;
	sorted = malloc(sizeof(listint_t));
	sorted->prev = NULL;
	sorted->next = NULL;
	temp = (int *)&sorted->n;
	sptr = sorted;
	*temp = ptr->n;
	ptr = ptr->next;
	while (ptr)
	{
		ptr2 = ptr;
		while (sptr->next)
			sptr = sptr->next;
		while (sptr && sptr > ptr->n)
		{
			
		}



		sptr = sorted;
		ptr = ptr->next;
	}
}
