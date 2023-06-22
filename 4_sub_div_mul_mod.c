#include "monty.h"

void stack_sub(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_mul(stack_t **stack, unsigned int line_number);




/**
 * stack_sub - subtracts the top element of the stack from the second top element
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second;
	int stack_size;

	for (stack_size = 0; first != NULL ; stack_size++)
	{
		first = first->next;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->prev = first->prev;

	second->n -= first->n;
	free(first);

	*stack = second;
}


/**
 * stack_div - subtracts the top element of the stack from the second top element
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second;
	int stack_size;

	for (stack_size = 0; first != NULL ; stack_size++)
	{
		first = first->next;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

  if (first->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	second->prev = first->prev;

	second->n /= first->n;
	free(first);

	*stack = second;
}



/**
 * stack_mul - multiplies the second top element of the stack with the top element
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack, *second;
	int stack_size;

	for (stack_size = 0; first != NULL ; stack_size++)
	{
		first = first->next;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->prev = first->prev;

	second->n *= first->n;
	free(first);

	*stack = second;
}
