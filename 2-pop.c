#include "monty.h"

/**
 * pop_op - Removes the top element of a stack_t stack
 * @stack: Stack
 * @line_number: Line number of the byte code operation
 */

void pop_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}

	if (command.mode && strcmp(command.mode, "queue") == 0)
	{
		dequeue(stack);
		return;
	}
	if (command.mode && strcmp(command.mode, "stack") == 0)
	{
		pop(stack);
		return;
	}
	pop(stack);
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

/**
 * pop - Removes a node at the top of a stack_t stack
 * @stack: stack_t stack
 */

void pop(stack_t **stack)
{
	stack_t *top = *stack;

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
 * dequeue - Removes node at the beginning of a stack_t queue
 * @stack: stack_t stack
 */

void dequeue(stack_t **stack)
{
	stack_t *temp = *stack;

	if (!stack || !*stack)
		return;

	if (temp->next)
	{
		*stack = temp->next;
		temp->next->prev = NULL;
		free(temp);
		return;
	}
	free(temp);
	*stack = NULL;
}
