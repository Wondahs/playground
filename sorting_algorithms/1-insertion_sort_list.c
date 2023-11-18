#include "sort.h"
#include <stdbool.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * @list: Double pointer to the head of the linked list
 *
 * Description:
 * Uses the insertion sort algorithm to sort the given doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = (*list)->next;
	listint_t  *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (head && head->next)
	{
		next = head->next;
		head->next = next->next;
		if (next->next)
			next->next->prev = head;
		current = *list;
		while (current && current != next)
		{
			if (current->n >= next->n)
			{
				next->prev = current->prev;
				if (current->prev)
					current->prev->next = next;
				else
					*list = next;
				current->prev = next;
				next->next = current;
			}
			else
			{
				next->next = current->next;
				if (current->next)
					current->next->prev = next;
				current->next = next;
				next->prev = current;
			}
			print_list(*list);
			current = current->next;
		}
		head = head->next;
	}
	(*list)->prev = NULL;
}
