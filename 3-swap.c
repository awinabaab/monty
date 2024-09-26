#include "monty.h"

/**
 * swap_op - Swaps the top two elements of a stack_t stack
 * @stack: Stack
 * @line_number: Line number of bytecode operation
 */

void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *next;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}

	next = top->next;
	top->prev = next;
	top->next = next->next;
	next->next = top;
	next->prev = NULL;
	*stack = next;
}
