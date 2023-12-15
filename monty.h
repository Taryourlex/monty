#ifndef MONTY_H
#define MONTY_H

#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct build - an external variable
 * @val: linenumber
 * @script: the provided montyscript
 * @buffer: buffer holding the lines
 * @stack: the stack structure
 * @type: decides if to function either as a stack or queue
 */
typedef struct build
{
	char *val;
	FILE *script;
	char *buffer;
	stack_t *stack;
	int type;
} format;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char *_itoa(int);
int my_isdigit(char *);
void (*retrieve(char *, unsigned int))(stack_t **, unsigned int)
void my_add(stack_t **, unsigned int);
void my_div(stack_t **, unsigned int);
void my_mod(stack_t **, unsigned int);
void my_mul(stack_t **, unsigned int);
void my_nop(stack_t **, unsigned int);
void my_pall(stack_t **, unsigned int);
void my_pchar(stack_t **, unsigned int);
void my_pint(stack_t **, unsigned int);
void my_pop(stack_t **, unsigned int);
void my_pstr(stack_t **, unsigned int);
void my_push(stack_t **, unsigned int);
void my_queue(stack_t **, unsigned int);
void my_rotl(stack_t **, unsigned int);
void my_rotr(stack_t **, unsigned int);
void my_stack(stack_t **, unsigned int);
void my_sub(stack_t **, unsigned int);
void my_swap(stack_t **, unsigned int);
void free_stack(stack_t *);
void free_form(void);
void q_push(stack_t **, int);
void open_monty(char **, unsigned int);

extern format fmt;
#endif
