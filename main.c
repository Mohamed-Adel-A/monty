#include "monty.h"

int main(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);		
	}
	(void) argv;
	(void) file;
	return (0);
}
