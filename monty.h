#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Stack Operations */
void push_op(stack_t **stack, unsigned int line_number);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void nop_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);

/* File Handlers */
FILE *open_file(char *filename);

/* Global Variables */
/**
 * struct command_s - opcode and its argument if any
 * @op: the opcode
 * @op_arg: the argument
 * @file: byte code file
 * @buffer: a line from @file
 * @stack: stack_t stack
 */
typedef struct command_s
{
	char *op;
	int op_arg;
	FILE *file;
	char *buffer;
	stack_t *stack;
} command_t;
extern command_t command;

/* Execution Handler */
void set_command(char *buffer, char *delim);
void execute(stack_t **stack, unsigned int line_number);
void (*get_op_func(char *op))(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void free_on_failure(void);

#endif /* MONTY_H */
