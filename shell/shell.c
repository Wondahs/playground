#include "main.h"
#include "printf.h"

#define MAX_ARGS 128
int main(int argc, char *argv[])
{
	int cmd_count = 1;
	char *cmd, *args[MAX_ARGS];

	(void)argc;
	while (1)
	{
		int tok = 0;
		/* Get command */
		cmd = getPrompt();
		if (cmd == NULL)
		{
			cmd_count++;
			continue;
		}
		tok = tokenize_cmd(cmd, args);
		if (tok == -1)
			break;
		call_exec(tok, args, cmd_count, argv[0]);
		free(cmd);
		cmd_count++;
	}
	return (0);
}
