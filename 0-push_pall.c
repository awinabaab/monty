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

	if ((command.op_arg && check_digit(command.op_arg) == 0) ||
			!command.op_arg)
	{
		fflush(stdout);
		dprintf(STDERR_FILENO,
				"L%d: usage: push integer\n",
				line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}

	new_element = malloc(sizeof(stack_t));
	if (!new_element)
	{
		fflush(stdout);
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_on_failure();
		exit(EXIT_FAILURE);
	}

	if (command.op_arg[0] == '-')
		new_element->n = atoi(command.op_arg + 1) * -1;
	new_element->n = atoi(command.op_arg);

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

/**
 * check_digit - Checks if a string is entirely a digit
 * @str: String
 *
 * Return: 0 if false, 1 if true
 */
int check_digit(const char *str)
{
	if (!*str || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
