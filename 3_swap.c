#include "monty.h"

void stack_swap(stack_t **stack, unsigned int line_number);

/**
 * stack_swap -  swaps the top two elements of the stack.
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second;

	if (first == NULL || first->next == NULL)
	{
		fprintf(stderr, "L%d:  can't swap, stack too short\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	second = first->next;

	first->next = second->next;
	second->prev = first->prev;

	first->prev = second;
	second->next = first;

	*stack = second;
	free(head);
}
