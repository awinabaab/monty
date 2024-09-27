#include "monty.h"

/**
 * pop_op - Removes the top element of a stack_t stack
 * @stack: Stack
 * @line_number: Line number of the byte code operation
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}
	if (top->next)
	{
		*stack = top->next;
		(*stack)->prev = NULL;
		free(top);
		return;
	}
	free(top);
	*stack = NULL;
}

/**
 * free_stack - Frees all the elements of a stack_t stack
 * @stack: Stack
 */

void free_stack(stack_t *stack)
{
	stack_t *current_element;

	if (!stack)
		return;

	while (stack)
	{
		current_element = stack;
		stack = stack->next;
		free(current_element);
	}
}

/**
 * free_on_failure - Frees when an invalid command is encountered
 */

void free_on_failure(void)
{
	free(command.op);
	free(command.buffer);
	if (command.op_arg)
		free(command.op_arg);
	free_stack(command.stack);
	fclose(command.file);
}
