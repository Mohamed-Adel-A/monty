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
	int stack_size, mid;

	for (stack_size = 0; first != NULL ; stack_size++)
	{
		first = first->next;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d:  can't swap, stack too short\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	mid = first->n;
	first->n = second->n;
	second->n = mid;
}
