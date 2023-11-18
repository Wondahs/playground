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
	listint_t  *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (head)
	{
		current = head;
		while (current->prev)
		{
			temp = current->prev;
			if (temp->n > current->n)
			{
				if (temp->prev)
					temp->prev->next = current;
				else
					*list = current;
				if (current->next)
					current->next->prev = temp;
				temp->next = current->next;
				current->prev = temp->prev;
				current->next = temp;
				temp->prev = current;
				print_list(*list);
				continue;
			}
			current = current->prev;

		}
		head = head->next;
	}
}
