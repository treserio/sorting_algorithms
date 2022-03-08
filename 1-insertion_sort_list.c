#include "sort.h"
/**
 * insertion_sort_list - Sorts a dbly linked list using insertion method
 * @list: a pointer to a pointer of the head of the dbly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *run, *swap;
	/* check for 1 value in list */
	if (!list || !*list || !(*list)->next)
		return;
	/* move forward and check back for values */
	for (run = (*list)->next; run; run = run->next)
	{
		for (swap = run; swap->prev && swap->prev->n > swap->n;)
		{
			if (swap->prev->prev)
			{
				swap->prev->prev->next = swap;
				if (swap->next)
				{
					swap->prev->next = swap->next;
					swap->next->prev = swap->prev;
				}
				else
					swap->prev->next = NULL;
				swap->next = swap->prev;
				swap->prev = swap->next->prev;
				swap->next->prev = swap;
			}
			else
			{
				if (swap->next)
				{
					swap->prev->next = swap->next;
					swap->next->prev = swap->prev;
				}
				else
					swap->prev->next = NULL;
				swap->prev->prev = swap;
				swap->next = swap->prev;
				swap->prev = NULL;
				*list = swap;
			}
			print_list(*list);
		}
	}
}
