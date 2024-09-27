#include "monty.h"

/**
 * pint_op - Prints the value at the top of the stack followed by a new line
 * @stack: Stack
 * @line_number: Line number of bytecode operation
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
