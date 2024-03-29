#include "monty.h"

/**
 * _stack -sets the format of data to stack
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _stack(stack_t **stack, unsigned int lnum)
{
	mt.type = 1;

	(void)stack;
	(void)lnum;
}

/**
 * _queue - sets the format of data to queue
 * @stack: stack
 * @lnum: line number
 *
 * Return: void
 */
void _queue(stack_t **stack, unsigned int lnum)
{
	mt.type = 0;

	(void)stack;
	(void)lnum;
}

/**
 * q_push - pushes to queue
 * @queue: queue
 * @num: num to push
 *
 * Return: void
 */
void q_push(stack_t **queue, int num)
{
	stack_t *new, *temp = *queue;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_xtrn();
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->prev = NULL;
	new->next = temp;

	if (*queue)
		temp->prev = new;
	*queue = new;
}

