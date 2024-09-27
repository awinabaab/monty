#include "monty.h"

/**
 * push_op - Adds an element to the top of a stack_s stack
 * @stack: Stack
 * @line_number: Line number of bytecode operation
 */

void push_op(stack_t **stack, unsigned int line_number)
{
	if ((command.op_arg && check_digit(command.op_arg) == 0) ||
			!command.op_arg)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_on_failure();
		exit(EXIT_FAILURE);
	}

	if (command.mode && strcmp(command.mode, "stack") == 0)
	{
		push(stack, command.op_arg);
		return;
	}

	if (command.mode && strcmp(command.mode, "queue") == 0)
	{
		enqueue(stack, command.op_arg);
		return;
	}

	push(stack, command.op_arg);
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
	if (!stack || !*stack)
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


/**
 * push - Adds a node to the top of a stack_t stack
 * @stack: stack_t stack
 * @s: data for new element
 */

void push(stack_t **stack, char *s)
{
	stack_t *new_element = NULL;

	new_element = malloc(sizeof(stack_t));
	if (!new_element)
	{
		fflush(stdout);
		fprintf(stderr, "Error: malloc failed\n");
		free_on_failure();
		exit(EXIT_FAILURE);
	}
	if (s[0] == '-')
		new_element->n = atoi(s + 1) * -1;
	else
		new_element->n = atoi(s);

	if (!*stack)
	{
		new_element->next = NULL;
		new_element->prev = NULL;
		*stack = new_element;
		return;
	}
	(*stack)->prev = new_element;
	new_element->next = *stack;
	new_element->prev = NULL;
	*stack = new_element;
}


/**
 * enqueue - Adds node to the end of a stack_t queue
 * @stack: stack_t stack
 * @s: data for new element
 */

void enqueue(stack_t **stack, char *s)
{
	stack_t *temp = *stack;
	stack_t *new_element = NULL;

	new_element = malloc(sizeof(stack_t));
	if (!new_element)
	{
		fflush(stdout);
		fprintf(stderr, "Error: malloc failed\n");
		free_on_failure();
		exit(EXIT_FAILURE);
	}
	if (s[0] == '-')
		new_element->n = atoi(s + 1) * -1;
	else
		new_element->n = atoi(s);
	new_element->next = NULL;

	if (!stack || !*stack)
	{
		*stack = new_element;
		return;
	}

	while (temp && temp->next)
		temp = temp->next;

	if (temp)
	{
		new_element->prev = temp;
		temp->next = new_element;
	}
}
