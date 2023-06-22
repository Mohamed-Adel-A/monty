#include "monty.h"

/*********************************/
int _isnumber(const char *str);
void stack_push(stack_t **stack, unsigned int line_number);
/*********************************/


/**
 * _isnumber - check if string is number
 * @str: the string to be checked
 *
 * Return: 1 if str is number, 0 if not
 */
int _isnumber(const char *str)
{
	int i = 0;
	
	if (str == NULL || str[0] == '\0')
		return (0);

	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}

	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}

	for (; str[i] != '\0' ; i++)
	{
		if ((str[i] < '0' || str[i] > '9'))
		{
			return (0);
		}
	}

	return (1);
}

/**
 * stack_push - push int to stack
 * @stack: stack head
 * @line_number: line number
 *
 * Return: void
 */
void stack_push(stack_t **stack, unsigned int line_number)
{
	int number;

	if (_isnumber(op_data.oparg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	number = atoi(op_data.oparg);
	add_stack(stack, number);

	
	printf("%u: stack push %s\n", line_number, op_data.oparg);
}

/**
 * malloc_error - handle error when malloc
 * @stack: stack head
 *
 * Return: void
 */
void malloc_error(stack_t **stack)
{
	fprintf(stderr, "Error: malloc failed");
	free(op_data.line);
	fclose(op_data.fd);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}


void add_stack(stack_t **stack, int n)
{
	stack_t *new, *head = *stack;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		malloc_error(head);
	}

	new->n = n;
	if (head != NULL)
	{
		head->prev = NULL;
	}
	new->next = head;
	new->prev = NULL;
	*head = new;
}
