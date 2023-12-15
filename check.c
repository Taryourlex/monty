#include "monty.h"
/**
 * _itoa - changes  to characters
 * @n: to cinvert
 * Return: the corresponding integer
 */
char *_itoa(int n)
{
	int len = snprintf(NULL, 0, "%d", n);
	char *val = malloc(len + 1);

	if (!val)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	snprintf(val, len + 1, "%d", n);
	return (val);
}

/**
 * check_digit - check if a string contains digits only
 * @numstr: string to be checked
 * Return: 1 if digit, 0 if not digit
 */
int check_digit(char *numstr)
{
	int i;

	if (numstr == NULL)
		return (0);
	if (numstr[0] == '-')
		numstr++;

	for (i = 0; numstr[i] != '\0'; i++)
	{
		if (numstr[i] < '0' || numstr[i] > '9')
			return (0);
	}
	return (1);
}
