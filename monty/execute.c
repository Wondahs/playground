#include "monty.h"

/**
 *
 *
 *
 *
 *
 *
 */
void execute(void)
{
	int i = 0, line_number = 1, j = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall}
	};
	char **lines = cmds->lines;
	void (*executor)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *stack = NULL;

	for (i = 0; i < cmds->line_count; i++)
	{
		char **command = cmds->args, *token = NULL;
		int num;

		token = strtok(lines[i], " ");
		while (j < MAX_ARGS && token != NULL)
		{
			command[j] = token;
			token = strtok(NULL, " ");
			j++;
		}
		num = atoi(command[1]);
		if (num == 0 && command[1][0] != '0' && command[1] != NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, command[0]);
			exit(EXIT_FAILURE);
		}
		for (j = 0; j < sizeof(ops) / sizeof(ops[0]); j++)
		{
			if (strcmp(command[0], ops[i].opcode) == 0)
			{
				executor = ops[i].f;
			}
		}
		if (executor != NULL)
			executor(&stack, line_number);
		else
			exit(EXIT_FAILURE);
		line_number++;
	}
}
