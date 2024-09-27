#include "monty.h"

/**
 * execute - Executes a bytecode command
 * @line_number: Line number of the command in the file
 * @stack: Stack to perform the command on
 */

void execute(stack_t **stack, unsigned int line_number)
{
	void (*op_func)(stack_t **, unsigned int) = get_op_func(command.op);

	if (command.op[0] == '#')
	{
		free(command.op);
		return;
	}

	if (!op_func)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, command.op);
		free_on_failure();
		exit(EXIT_FAILURE);
	}

	op_func(stack, line_number);
	free(command.op);
}
