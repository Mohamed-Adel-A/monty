#include "monty.h"

void stack_pchar(stack_t **stack, unsigned int line_number);


/**
 * stack_pchar -  prints the char at the top of the stack.
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void) line_number;
	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (head->n < 0 || head->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", head->n);
}


/**
 * stack_pstr - prints the string starting at the top of the stack.
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	while (head != NULL && (head->n > 0 && head->n <= 127))
	{
		printf("%c\n", head->n);
		head = head->next;
	}
	printf("\n");
}




