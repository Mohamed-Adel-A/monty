#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fd;
	char *filename;

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
	
	(void) argv;
	return (0);
}
