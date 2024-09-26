#include "monty.h"

/**
 * open_file - Opens a monty bytecode file
 * @filename: Filename
 *
 * Return: Pointer to opened file
 */

FILE *open_file(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}
