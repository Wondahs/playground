#include "monty.h"

/**
 *
 *
 *
 *
 *
 *
 */
void free_stack(stack_t *stack)
{
	stack_t *temp, *current;

	if (!stack || stack == NULL)
		return;
	current = stack;

	if (current->next == NULL)
	{
		free(current);
		current = NULL;
		return;
	}
	while (current->next != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		temp = NULL;
	}
	free(current);
	current = NULL;
}

/**
 *
 *
 *
 *
 *
 */
void free_all(stack_t *stack)
{
	int i;

	free_stack(stack);

	for (i = 0; i < cmds->line_count; i++)
		free(cmds->lines[i]);

	free(cmds);
}
