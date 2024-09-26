#include "monty.h"

command_t command = {NULL, -1, NULL, NULL, NULL};

/**
 * main- Monty byte code interpreter
 * @argv: Command line arguments
 * @argc: Size of @argv
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	FILE *file;
	unsigned int line_number = 0;
	char *buffer = NULL;
	size_t len = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = open_file(argv[1]);
	command.file = file;
	while (!feof(file) && !ferror(file))
	{
		if (getline(&buffer, &len, file) != -1)
		{
			command.buffer = buffer;
			if (*buffer == '\n' || *buffer == '#')
				continue;
			line_number++;
			set_command(buffer, " \t\n");
			execute(&stack, line_number);
			command.stack = stack;
		}
	}
	pall_op(&stack, line_number);
	free(buffer);
	fclose(file);
	free_stack(stack);
	return (0);
}
