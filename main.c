#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * monty - monty interpreter
 * @argc: no of arguments
 * @argv: monty file location
 * Return: 0(Success)
 */
int monty(int argc, char *argv[])
{
	char *cnt;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		cnt = NULL;
		read_line = getline(&cnt, &size, file);
		bus.cnt = cnt;
		count++;
		if (read_line > 0)
		{
			execute(cnt, &stack, count, file);
		}
		free(cnt);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
