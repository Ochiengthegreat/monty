#include "main.h"
/**
 * fq_pint - prints the top
 * @head: stack head
 * @count: line_number
 * Return: no return
*/
void fq_pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.cnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
