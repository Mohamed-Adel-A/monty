#include "monty.h"


/**
 * stuct op_data - instuction data
 * @line: instruction line
 * @opcode: opcode
 * @oparg: op argument
 *
 */
typedef struct op_data
{
	char *line;
	char *opcode;
	char *oparg;	
} op_data_t;

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
	char *filename, *line = NULL, opcode, oparg;
	size_t line_size = 0, line_count = 1;
	ssize_t ret_getline = 1, ret_execute_line;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);		
	}

	filename = argv[1];
	fd = fopen(filename, "r");
	if(fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	for (line_count = 0; ret_getline > 0 ; line_count++)
	{
		ret_getline = getline(&line, &line_size, fd);
		if (ret_getline > 0)
		{
			opcode = strtok(line, " \n");
			if (opcode[0] == "#")
			{
				free(line);
				continue;
			}
			opfunction = get_op_function();
			ret_execute_line = execute_line();
			if (ret_execute_line == -1)
			{
				fprintf()
			}
		}
		free(line);		
	}

	return (0);
}

execute_line()
{
	int i = 0;
	opcode_functions_t opfunc[] = { {"push", stack_push},
					{"pall", stack_pull},
					{"pint", stack_pint),
					{NULL, NULL}
					};

	for (i = 0, opfunc[i] != NULL, i++)
	{
		if (strcmp(opcode, opfunc[i].opcode == 0)
			return (opfunc[i].opfunction);
	}
	return (NULL);

}
int get_op_function()()
