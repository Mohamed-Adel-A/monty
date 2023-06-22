#include "monty.h"

/**
 * _isnumber - check if string is number
 * @str: the string to be checked
 *
 * Return: 1 if str is number, 0 if not
 */
int _isnumber(const char *str)
{
	int i = 0;

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


void stack_push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (_isnumber(op_data.oparg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
				line_number);
		free(op_data.line);
		fclose(op_data.fd);
		free_stack(&stack);
		exit(EXIT_FAILURE);
  }
	printf("%u: stack push %s\n", line_number, op_data.oparg);
}
