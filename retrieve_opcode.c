#include "monty.h"

/**
 * retrieve - retrieves the right operation
 * @opcode: opcode name
 * @detail: line to check
 * Return: none
 */

void (*retrieve(char *opcode, unsigned int detail))(stack_t **, unsigned int)
{
	instruction_t op_code[] = {
		{"mod", my_mod}, {"add", my_add}, {"mul", my_mul}, {"sub", my_sub},
		{"div", my_div}, {"pop", my_pop}, {"nop", my_nop},
		{"push", my_push}, {"pint", my_pint}, {"pchar", my_pchar},
		{"pall", my_pall}, {"swap", my_swap}, {"pstr", my_pstr},
		{"rotr", my_rotr}, {"rotl", my_rotl}, {"stack", my_stack},
		{"queue", my_queue}, {NULL, NULL},
	};
	int i, check;

	for (i = 0; op_code[i].opcode; i++)
	{
		check = strcmp(opcode, op_code[i].opcode);
		if (check == 0)
			return (op_code[i].f);
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", detail, opcode);
	exit(EXIT_FAILURE);
}
