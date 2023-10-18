#include "monty.h"

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
