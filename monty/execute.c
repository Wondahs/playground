#include "monty.h"

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
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall}
	};
	void (*executor)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *stack = NULL;

	for (i = 0; i < cmds->line_count; i++)
	{
		int j = 0;
		char *token = NULL;
		int num;

		executor = NULL;
		token = strtok(cmds->lines[i], " ");
		while (j < MAX_ARGS && token != NULL)
		{
			cmds->args[j] = token;
			token = strtok(NULL, " ");
			j++;
		}
		num = atoi(cmds->args[1]);
		if (num == 0 && cmds->args[1][0] != '0' && cmds->args[1] != NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmds->args[0]);
			free_all(stack);
			exit(EXIT_FAILURE);
		}
		cmds->num = num;
		for (j = 0; j < sizeof(ops) / sizeof(ops[0]); j++)
		{
			if (strcmp(cmds->args[0], ops[j].opcode) == 0)
			{
				executor = ops[j].f;
				break;
			}
		}
		if (executor != NULL)
			executor(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmds->args[0]);
			free_all(stack);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free_stack(stack);
}
