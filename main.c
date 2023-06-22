#include "monty.h"

int main(int argc, char **argv)
{
	FILE *f;
	char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);		
	}

	filename = argv[1];
	f = fopen(filename, "r");
	if(f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	(void) argv;
	(void) file;
	return (0);
}
