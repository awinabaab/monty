#include "monty.h"

/**
 * pstr_op - Prints the value at the top of the stack followed by a new line
 * @stack: Stack
 * @line_number: Line number of bytecode operation
 */

void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	(void)line_number;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}

	while (top && top->n != 0 && isascii(top->n))
	{
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}
