#include "monty.h"
#include <math.h>

/**
 *get_dnodeint_at_index - Retrieves node at given index
 *@head: Pointer to head node
 *@index: Given index
 *
 * Return: Address of node at given index
 */
int num_at_index(stack_t* stack, unsigned int index)
{
	unsigned int i = 0;
	stack_t *current;

	current = stack;

	while (current)
	{
		if (i == index)
			return (current->n);
		current = current->next;
		i++;
	}
	return (INT_MIN);
}

/**
 *delete_dnodeint_at_index - Deletes node at specified index
 *@head: Pointer to pointer to head node
 *@index: Index
 *
 *Return: 1 on success, -1 otherwise
 */
int delete_stack_at_index(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *current;

	if (!head || *head == NULL)
		return (-1);
	current = *head;

	while (current)
	{
		if (index == 0)
		{
			if (current->next)
				current->next->prev = NULL;
			*head = current->next;
			free(current);
			current = NULL;
			return (1);
		}
		if (index == i)
		{
			if (current->prev)
				current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			free(current);
			current = NULL;

			return (1);
		}
		i++;
		current = current->next;
	}
	return (-1);
}

/**
 *dlistint_len - Counts nodes in a dlistint_t list
 *@h: Pointer to node head
 *
 *
 *Return: Number of nodes
 */
int stack_len(stack_t *h)
{
	size_t count = 0;
	stack_t *current;

	if (h == NULL || !h)
		return (0);
	current = h;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
