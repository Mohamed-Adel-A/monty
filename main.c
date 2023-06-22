#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;
	char *error;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);		
	}
	(void) argv;
	(void) file;
	return (0);
}
