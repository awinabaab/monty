#include "monty.h"

/**
 * pchar_op - Prints the value at the top of the stack followed by a new line
 * @stack: Stack
 * @line_number: Line number of bytecode operation
 */

void pchar_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}
	if (!isascii((*stack)->n))
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
