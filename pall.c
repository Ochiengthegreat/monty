#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @line: no used
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int line)
{
	stack_t *h;
	(void)line;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
