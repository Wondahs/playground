#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *add_dnodeint - Adds new node at the head of a dlistint_t list
 *@head: Pointer to Pointer to first node
 *@line_number: Line number
 *
 *Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	(void)line_number;
	if (!cmds->num)
		return;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = cmds->num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*stack == NULL)
		*stack = newNode;
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
}

/**
 *print_dlistint - Prints data in a dlistint_t list
 *@h: Head of list
 *
 *
 *
 *Return: Number of node
 */
void pall(stack_t **stack, unsigned int line_number)
{
	size_t count = 0;
	stack_t *current;

	(void)line_number;
	if (*stack == NULL || !*stack)
		return;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		count++;
		current = current->next;
	}
}

/**
 *
 *
 *
 *
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int len, stack_0 = 0, stack_1 = 0, result = 0;

	stack_t *stack_zero = *stack;
	stack_t *stack_one = *stack, *current = *stack;

	len = stack_len(current);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(current);
		exit(EXIT_FAILURE);
	}

	stack_0 = num_at_index(stack_zero, 0);
	stack_1 = num_at_index(stack_one, 1);
	result = stack_1 - stack_0;
	
	delete_stack_at_index(stack, 0);
	delete_stack_at_index(stack, 0);

	cmds->num = result;
	push(stack, line_number);
}


/**
 *
 *
 *
 *
 *
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int len, first, next;
	stack_t *head = *stack, *current = *stack;

	len = stack_len(head);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	first = current->n;
	next = current->next->n;

	delete_stack_at_index(stack, 0);
	delete_stack_at_index(stack, 0);

	cmds->num = first;
	push(stack, line_number);
	cmds->num = next;
	push(stack, line_number);
}
