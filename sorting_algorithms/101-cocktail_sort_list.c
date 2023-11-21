#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

/**
 *swap_nodes - Swaps nodes.
 *@list: Head node
 *@current: Node to move forward.
 *@nxt: Node to move backward.
 */
void swap_nodes(listint_t **list, listint_t **current, listint_t **nxt)
{
	listint_t *head = *current, *next = *nxt;

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
}


/**
 *cocktail_sort_list - Sorts linked list using cocktail sort algorithm.
 *@list: Address of head pointer.
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = *list, *prev, *next, *temp;
	bool sorted = false;

	if (!head || head->next == NULL)
		return;

	while (!sorted)
	{
		sorted = true;
		while (head && head->next)
		{
			next = head->next;
			if (head->n > next->n)
			{
				sorted = false;
				swap_nodes(list, &head, &next);
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
				swap_nodes(list, &prev, &head);
				print_list(*list);
			}
			head = head->prev;
		}
	}
}
