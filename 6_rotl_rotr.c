#include "monty.h"

/**
 * stack_rotl -  rotates the stack to the top.
 * The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *last, *node = *stack;

	(void) line_number;
	if (first == NULL || first->next == NULL)
		return;

	while (node != NULL)
	{
		last = node;
		node = node->next;
	}

	last->next = first->next;
	first->prev = last->prev;

	last->prev = NULL;
	first->next = NULL;

	*stack = last;
}
