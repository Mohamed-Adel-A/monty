#include "monty.h"

/***********************************************************/
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
/***********************************************************/

/**
 * stack_pall - push int to stack
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;
	while (head != NULL)
	{
		printf("%i\n", head->n);
		head = head->next;
	}

	/*printf("%u: stack pall %s\n", line_number, op_data.oparg);*/
}



void stack_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%i\n", head->n); 
}
