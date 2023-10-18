#include "monty.h"

/**
 *
 *
 *
 *
 */
void tokenizer(int i)
{
	char *token = NULL;
	int j = 0;

	token = strtok(cmds->lines[i], " ");
	while (j < MAX_ARGS && token != NULL)
	{
		cmds->args[j] = token;
		token = strtok(NULL, " ");
		j++;
	}
}

void check_op(stack_t **stack, int line_number)
{
	long unsigned int j;

	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"sub", sub}
	};
	void (*executor)(stack_t **stack, unsigned int line_number) = NULL;

	for (j = 0; j < sizeof(ops) / sizeof(ops[0]); j++)
	{
		if (strcmp(cmds->args[0], ops[j].opcode) == 0)
		{
			executor = ops[j].f;
			break;
		}
	}
	if (executor != NULL)
		executor(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmds->args[0]);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
}
