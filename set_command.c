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

	token = strtok(buffer, delim);
	while (token && i < 2)
	{
		tokens[i] = strdup(token);
		command.op = tokens[0] ? tokens[0] : NULL;
		if (i >= 1 && tokens[1])
			command.op_arg = tokens[1] ? tokens[1] : NULL;
		token = strtok(NULL, delim);
		i++;
	}
}
