#include "monty.h"

op_data_t op_data = {NULL, NULL, NULL, 0};



void stack_pall(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	printf("%u: stack pall %s\n", line_number, op_data.oparg);
}

void stack_pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	printf("%u: stack pint %s\n", line_number, op_data.oparg);
}

/**
 * free_stack - free stack
 * @stack: stack head
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *next;

	if (stack == NULL)
		return;

	while(stack != NULL)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

/**
 * execute_line - get opcode and arg and execute the line
 * @stack: stack head
 * @line: the line readed from the file
 * @line_number: line number
 *
 * Return: 0 in success, -1 in opcode is wrong
 */
ssize_t execute_line(stack_t **stack, char *line, unsigned int line_number)
{
	int i = 0;
	instruction_t opfunc[] = {
								{"push", stack_push},
								{"pall", stack_pall},
								{"pint", stack_pint},
								{NULL, NULL}
							};

	op_data.opcode = strtok(line, " \n");
	if (!op_data.opcode || op_data.opcode[0] == '#')
		return (0);

	op_data.oparg = strtok(NULL, " \n");
	for (i = 0; opfunc[i].opcode != NULL; i++)
	{
		if (strcmp(op_data.opcode, opfunc[i].opcode) == 0)
		{
			opfunc[i].f(stack, line_number);
			break;
		}
	}
	if (opfunc[i].f == NULL)
		return (-1);

	return (0);
}


/**
 * main - main function
 * @argc: argc
 * @argv: argv
 *
 * Return: 0 success, otherwise failure
 */
int main(int argc, char **argv)
{
	FILE *fd;
	char *filename, *line = NULL;
	size_t line_size = 0;
	ssize_t ret_getline = 1, ret_execute_line;
	unsigned int line_number;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	for (line_number = 1; ret_getline > 0 ; line_number++)
	{
		ret_getline = getline(&line, &line_size, fd);
		if (ret_getline > 0)
		{
			ret_execute_line = execute_line(&stack, line, line_number);
			if (ret_execute_line == -1)
			{
				fflush(0);
				fprintf(stderr, "L%d: unknown instruction %s\n",
						line_number, op_data.opcode);
				free(line);
				fclose(fd);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
		}
		free(line);
		line = NULL;
	}
	free_stack(stack);
	return (0);
}
