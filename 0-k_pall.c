#include "monty.h"

/**
 * k_pall - prints all value of the stack from the top
 * @head: stack head
 * @counter: no used
 *
 * Return: none
 */

void k_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
