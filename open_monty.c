#include "monty.h"

/**
 * open_monty - a function that opens and runs monty file
 * @argv: argument
 * @lnum: each line in the monty file
 * Return: 0
 */
void open_monty(char **argv, unsigned int lnum)
{
	char *detail, *chr;
	void (*func)(stack_t **stack, unsigned int lnum);

	fmt.script = fopen(argv[1], "r");
	if (fmt.script == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (true)
	{
		lnum++;

		fmt.buffer = malloc(sizeof(char) * 1024);
		if (fmt.buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		detail = fgets(fmt.buffer, 1024, fmt.script);
		if (detail == NULL)
			break;

		chr = strtok(fmt.buffer, " \n\t\a\r");
		fmt.val = strtok(NULL, " \n\t\a\r");
		if (chr != NULL && chr[0] != 35)
		{
			func = retrieve(chr, lnum);
			func(&fmt.stack, lnum);
		}
		free(fmt.buffer);
