#include "monty.h"
/**
 * free_format - frees the format structure
 * Return: nothing
 */
void free_format(void)
{
	fclose(fmt.script);
	free(fmt.buffer);
	free_stack(fmt.stack);
}

/**
 * free_stack - frees the xtrn stack
 * @head: the stack to free
 * Return: nothing
 */
void free_stack(stack_t *head)
{
	stack_t *right_node = NULL;

	while (head != NULL)
	{
		right_node = head;
		head = head->next;
		free(right_node);
	}
}
