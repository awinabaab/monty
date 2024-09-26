#include "monty.h"

/**
 * push_op - Adds an element to the top of a stack_s stack
 * @stack: Stack
 * @line_number: Line number of bytecode operation
 */

void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *new_element = NULL;

	if (command.op_arg == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(command.op);
		exit(EXIT_FAILURE);
	}

	new_element = malloc(sizeof(stack_t));
	if (!new_element)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_element->n = command.op_arg;
	command.op_arg = 0;

	if (!top)
	{
		new_element->next = NULL;
		new_element->prev = NULL;
		*stack = new_element;
		return;
	}

	top->prev = new_element;
	new_element->next = top;
	new_element->prev = NULL;
	*stack = new_element;
}


/**
 * pall_op - Prints all the values on a stack_s stack starting from the top
 * @stack: Stack
 * @line_number: Line number of bytecode operation
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	(void)line_number;
	if (!*stack)
		return;

	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
}
