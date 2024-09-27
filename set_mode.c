#include "monty.h"

/**
 * set_queue - Sets the mode of the interpreter queue
 * @stack: A stack_t stack/queue
 * @line_number: Line number of the opcode
 */

void set_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	command.mode = "queue";
}


/**
 * set_stack - Sets the mode of the interpreter stack
 * @stack: A stack_t stack/queue
 * @line_number: Line number of the opcode
 */

void set_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	command.mode = "stack";
}
