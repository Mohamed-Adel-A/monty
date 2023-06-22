#include "monty.h"


void stack_rotl(stack_t **stack, unsigned int line_number);
void stack_rotr(stack_t **stack, unsigned int line_number);

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
	stack_t *first = *stack, *last = *stack;

	(void) line_number;
	if (first == NULL || first->next == NULL)
		return;

	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = first;
	*stack = first->next;
	(*stack)->prev = NULL;

	first->next = NULL;
	first->prev = last;
}


/**
 * stack_rotr - rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;

	(void) line_number;
	copy = *stack;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *stack;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*stack)->prev = copy;
	(*stack) = copy;
}
