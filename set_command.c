#include "monty.h"

/**
 * set_command - Set bytcode command variables
 * @buffer: Bytecode command
 * @delim: Delimiters
 */

void set_command(char *buffer, char *delim)
{
	char *token;
	char *tokens[2] = {NULL, NULL};
	int i = 0;
	int ch = 0;

	token = strtok(buffer, delim);
	while (token && i < 2)
	{
		tokens[i] = strdup(token);
		command.op = tokens[0] ? tokens[0] : " ";
		token = strtok(NULL, delim);
		i++;
	}

	if (i >= 1 && tokens[1])
	{
		while (tokens[1][ch])
		{
			if (!(tokens[1][ch] > 47) && !(tokens[1][ch] < 58))
			{
				command.op_arg = -1;
				return;
			}
			ch++;
		}
		command.op_arg = atoi(tokens[1]);
		free(tokens[1]);
	}
}
