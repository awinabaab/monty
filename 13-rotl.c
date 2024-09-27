#include "monty.h"

/**
 * rotl_op - Rotates the stack to the top
 * Description: The top element becomes the last one,
 * and the second top element becomes the first one
 *
 * @stack: A stack_t stack
 * @line_number: Line number of the opcode
 */

void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp = *stack;
	stack_t *tail = NULL;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	while (temp->next)
		temp = temp->next;

	if (!temp)
		return;
	tail = temp;

	if (tail)
	{
		*stack = (*stack)->next;
		tail->next = head;
		head->prev = tail;
		head->next = NULL;
		(*stack)->prev = NULL;
	}
}
