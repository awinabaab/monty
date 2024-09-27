#include "monty.h"

/**
 * get_op_func - Gets the appropriate function for a bytcode op
 * @op: Function to look for
 *
 * Return: The appropriate function
 */

void (*get_op_func(char *op))(stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;
	instruction_t op_funcs[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{"sub", sub_op},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
		{"rotl", rotl_op},
		{NULL, NULL}
	};

	for (i = 0; op_funcs[i].opcode; i++)
		if (strcmp(op, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);

	return (NULL);
}
