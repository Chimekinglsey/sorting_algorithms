#include "sort.h"

/**
* insertion_sort_list - this function sorts an
*	array of integers in ascending order
* @list: the doubly linked list to sort
* Return - Nothing
*
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *prevp;

	if (*list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;

	while (curr != NULL)
	{
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			prevp = prev->prev;
			prev->next = curr->next;
			if (curr->next != NULL)
			curr->next->prev = prev;
			curr->next = prev;
			curr->prev = prevp;
			if (prevp != NULL)
			prevp->next = curr;
			else
			*list = curr;
			prev->prev = curr;
			prev = curr->prev;
			print_list(*list);
		}
	curr = curr->next;
	}
}

