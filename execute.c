#include "main.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @count: line_count
* @file: poiner to monty file
* @cnt: line cnt
* Return: no return
*/
int execute(char *cnt, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push", fq_push}, {"pall", fq_pall}, {"pint", fq_pint},
				{"pop", fq_pop},
				{"swap", fq_swap},
				{"add", fq_add},
				{"nop", fq_nop},
				{"sub", fq_sub},
				{"div", fq_div},
				{"mul", fq_mul},
				{"mod", fq_mod},
				{"pchar", fq_pchar},
				{"pstr", fq_pstr},
				{"rotl", fq_rotl},
				{"rotr", fq_rotr},
				{"queue", fq_queue},
				{"stack", fq_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(cnt, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(cnt);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
