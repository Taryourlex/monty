#include "monty.h"

form fmt;

/**
 * main - this checks the number of arguments
 * @argv: the arg vector
 * @argc: argument count
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fmt.stack = NULL;
	fmt.buffer = NULL;
	fmt.value = NULL;
	fmt.type = 1;

	open_monty(argv, 0);

	return (0);
}
