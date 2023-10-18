#include "monty.h"
#include <string.h>

/**
 *
 *
 *
 *
 *
 *
 */
void executer(void)
{
	int i = 0, line_number = 1;
	stack_t *stack = NULL;

	for (i = 0; i < cmds->line_count; i++)
	{
		char *endptr;
		int num;

		cmds->args[0] = NULL;
		cmds->args[1] = NULL;
		tokenizer(i);
		if (cmds->args[1] != NULL)
		{
			num = (int)strtol(cmds->args[1], &endptr, 10);
			if (endptr == cmds->args[1])
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
line_number, cmds->args[0]);
				free_all(stack);
				exit(EXIT_FAILURE);
			}
			cmds->num = num;
		}
		if (strcmp(cmds->args[0], "push") == 0
		&& cmds->args[1] == NULL)
		{
			continue;
			line_number++;
		}
		check_op(&stack, line_number);
		line_number++;
	}
	free_stack(stack);
}
