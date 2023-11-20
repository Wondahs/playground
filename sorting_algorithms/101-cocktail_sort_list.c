#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

/**
 *
 *
 *
 *
 *
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = *list, *prev, *next, *temp;
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		while (head && head->next)
		{
			next = head->next;
			if (head->n > next->n)
			{
				sorted = false;
				head->next = next->next;
				if (next->next)
					next->next->prev = head;
				next->prev = head->prev;
				if (head->prev)
					head->prev->next = next;
				else
					*list = next;
				next->next = head;
				head->prev = next;
				print_list(*list);
			}
			temp = head;
			head = head->next;
		}
		head = temp;
		if (sorted)
			break;
		while (head && head->prev)
		{
			prev = head->prev;
			if (prev->n > head->n)
			{
				sorted = false;
				prev->next = head->next;
				if (head->next)
					head->next->prev = prev;
				head->prev = prev->prev;
				if (prev->prev)
					prev->prev->next = head;
				else
					*list = head;
				head->next = prev;
				prev->prev = head;
				print_list(*list);
			}
			head = head->prev;
		}
	}
}
