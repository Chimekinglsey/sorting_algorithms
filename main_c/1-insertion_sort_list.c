#include "sort.h"

/**
* insertion_sort - this function sorts an array of integers in ascending order
* @list: the doubly linked list to sort
* Return - Nothing
*
*void swap(listint_t **list, listint_t *node1, listint_t *node2)
*{
*	listint_t *ptr;
*	if (node2->next != NULL)
*	{
*		ptr = node2->next;
*		node1->next = ptr;
*		ptr->prev = node1;
*		node2->next = node1->prev;
*		node1->prev = node2->next;
*		node2->prev = node1->prev->next;
*		node1->prev->next = node2->prev;
*	}
*	else
*	{
*		*list = node2;
*		node1->prev = node2;
*		node1 = node2->prev;
*	}
*}
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *tmp, *ptr, *prevp, *nextp;
	head = *list;
	tmp = head;
	nextp = tmp->next;
	prevp = tmp->prev;
	for(; tmp->next != NULL; tmp = tmp->next)
	{
		while(tmp->n)
		{
			if(tmp->n > nextp->n)
			{
				ptr = tmp->next->next;
				tmp->next = ptr->prev;
				ptr->prev = tmp->next;
				nextp->next = prevp;
				prevp = nextp->next;
				nextp->prev = prevp->next;
				prevp->next = nextp->prev;
				print_list(head);
				tmp = head;
			}
			else	
				print_list(head);
		tmp = tmp->next;
		}
	}
}
