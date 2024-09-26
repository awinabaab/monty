#include "monty.h"

/**
 * mul_op - Adds the top two elements of a stack_t stack
 * @stack: Stack
 * @line_number: Line number of the opcode command
 */

void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *next_element;

	if (!stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}

	next_element = top->next;
	next_element->n *= top->n;
	next_element->prev = NULL;
	pop_op(stack, line_number);
	*stack = next_element;
}
