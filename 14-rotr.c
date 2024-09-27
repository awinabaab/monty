#include "monty.h"

/**
 * rotr_op - Rotates the stack to the bottom
 * Description: The last element becomes the top element of the stack
 *
 * @stack: A stack_t stack
 * @line_number: Line number of the opcode
 */

void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp = *stack;
	stack_t *tail = NULL;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	while (temp->next)
		temp = temp->next;

	if (temp)
		tail = temp;

	if (tail)
	{
		if (tail->prev)
			tail->prev->next = NULL;
		tail->next = head;
		tail->prev = NULL;
		head->prev = tail;
		*stack = tail;
	}
}
